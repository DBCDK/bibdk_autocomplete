<?php

/**
 * @file
 * Admin settings for bibliotek.dk autocomplete.
 */

/**
 * General settings form for bibdk_autocomplete module.
 */
function bibdk_autocomplete_settings_form($form, &$form_state) {
  $form['bibdk_autocomplete_webservice'] = array(
    '#type' => 'fieldset',
    '#title' => t('Webservice definition', array(), array('context' => 'bibdk_autocomplete')),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
  );

  $form['bibdk_autocomplete_webservice']['bibdk_autocomplete_rest_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Autocomplete URL', array(), array('context' => 'bibdk_autocomplete')),
    '#size' => 73,
    '#required' => TRUE,
    '#description' => t('Endpoint URL for the autocomplete REST service.', array(), array('context' => 'bibdk_autocomplete')),
    '#default_value' => variable_get('bibdk_autocomplete_rest_url', NULL),
  );

  return system_settings_form($form);

}

/**
 * Validate handler for bibdk_autocomplete_settings_form().
 */
function bibdk_autocomplete_settings_form_validate($form, &$form_state) {
  $form_state['values']['bibdk_autocomplete_rest_url'] = trim($form_state['values']['bibdk_autocomplete_rest_url'], $character_mask = " \t\n\r\0\x0B/");
}
