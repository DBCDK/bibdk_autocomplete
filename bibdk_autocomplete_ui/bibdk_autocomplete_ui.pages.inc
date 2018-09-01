<?php

/**
 * @file
 * Frontend forms and menu callbacks for bibdk_autocomplete_ui module.
 */

/**
 * Callback function used when input is entered in a search field.
 *
 * @param      $p_uuid
 * @param      $v_uuid
 * @param      $string
 * @see: https://github.com/DBCDK/ortograf
 */
function bibdk_autocomplete_ui_callback($p_uuid, $v_uuid, $string = '') {

  if (strlen($string) < 3) {
    drupal_json_output(array());
    drupal_exit();
  }

  $matches = array();
  $query['q'] = strtolower($string);

  $settings = variable_get('bibdk_autocomplete_ui_settings', array());
  $query = array_merge($query, $settings);

  $vars = variable_get('bibdk_autocomplete_ui_var', array());
  $value_vars = $vars[$p_uuid]['vars'][$v_uuid];
  unset($value_vars['autocomplete']);
  $query['type'] = $value_vars['type'];

  // Try to use cache for the query.
  $cid = md5(serialize($query));
  if ($cache = cache_get($cid, 'cache_bibdk_autocomplete')) {
    $matches = $cache->data;
  }
  else {
    $suggestions = bibdk_autocomplete_get_suggestions($query);
    // Maximum space in suggestions dropdown is 64 characters.
    // Maximum characters for search query string is 256 characters.
    foreach ($suggestions as $suggestion) {
      $val = truncate_utf8($suggestion, 64, TRUE, TRUE, 1);
      $key = truncate_utf8($suggestion, 256, TRUE, FALSE, 1);
      $key = trim($key, " \t\n\r\0\x0B?"); // trim whitespace and question mark.
      if (strpos($suggestion, ' ')) {
        $key = '"' . str_replace('"', '\"', $key) . '"';
      }
      $matches[$key] = $val;
    }

    // Store the matches in cache for faster lookup next time.
    if (sizeof($matches) > 0) {
      cache_set($cid, $matches, 'cache_bibdk_autocomplete', CACHE_TEMPORARY);
    }
  }

  // Return the result to the form in json
  drupal_json_output($matches);
  drupal_exit();
}

/**
 * Callback for autocomplete behaviour.
 */
function bibdk_autocomplete_ui_behaviour_callback() {
  $behaviour_data = $_POST;
  $settings = variable_get('bibdk_autocomplete_ui_var', array());
  foreach ($behaviour_data['ortograf'] as $key => $fields) {
    if (!isset($fields['suggestions'])) {
      unset($behaviour_data['ortograf'][$key]);
      continue;
    }
    $p_uuid = $fields['pageUuid'];
    $i_uuid = $fields['inputUuid'];
    $type = $settings[$p_uuid]['vars'][$i_uuid]['type'];
    $behaviour_data['ortograf'][$key]['type'] = $type;
    unset($behaviour_data['ortograf'][$key]['id']);
  }
  module_invoke_all('bibdk_behaviour_request', $behaviour_data);
}

