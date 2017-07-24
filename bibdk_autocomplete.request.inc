<?php

class openSuggestionTerm extends TingClientRequest implements ITingClientRequestCache {

  protected $cacheKey;

  /**
   * Get outputType parameter.
   *
   * @return string
   */
  public function getOutputType() {
    return 'json';
  }

  public function processResponse(stdClass $result) {
    return $result;
  }

  /** Implementation of ITingClientRequestCache */

  /** \brief ITingClientRequestCache::cacheKey; get a cachekey
   *
   * @return string
   */
   public function cacheKey() {
    $params = $this->getParameters();
    $ret = '';
    $this->make_cache_key($params, $ret);

    return md5($ret);
  }

  /** \brief make a cachekey based on request parameters
   *
   * @param array $params
   * @param string $ret
   */
   private function make_cache_key($params, &$ret) {
    foreach ($params as $key => $value) {
      if (is_array($value)) {
        // recursive
        $ret .= $key;
        $this->make_cache_key($value, $ret);
      }
      else {
        $ret .= $value;
      }
    }
  }

  /** \brief TingClientRequestCache::cacheEnable; Check if cache is enabled
   *
   * @return value of variable (drupal_get)
   */
   public function cacheEnable($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_enable);
  }

  /**\brief set timeout of cache
   *
   * @return mixed value of variable (variable_get)
   */
   public function cacheTimeout($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_lifetime, '1');
  }

  /* \brief implements ITingClientRequestCache::cacheBin
   *
   * @return string; name of cachebin
   */
   public function cacheBin() {
    return 'cache_autocomplete_webservice';
  }
  
  /** end ITingClientRequestCache * */

}


class openSuggestionFacetspell extends TingClientRequest implements ITingClientRequestCache {

  protected $cacheKey;

  /**
   * Get outputType parameter.
   *
   * @return string
   */
  public function getOutputType() {
    return 'json';
  }

  public function processResponse(stdClass $result) {
    return $result;
  }

  /** Implementation of ITingClientRequestCache */

  /** \brief ITingClientRequestCache::cacheKey; get a cachekey
   *
   * @return string
   */
   public function cacheKey() {
    $params = $this->getParameters();
    $ret = '';
    $this->make_cache_key($params, $ret);

    return md5($ret);
  }

  /** \brief make a cachekey based on request parameters
   *
   * @param array $params
   * @param string $ret
   */
   private function make_cache_key($params, &$ret) {
    foreach ($params as $key => $value) {
      if (is_array($value)) {
        // recursive
        $ret .= $key;
        $this->make_cache_key($value, $ret);
      }
      else {
        $ret .= $value;
      }
    }
  }

  /** \brief TingClientRequestCache::cacheEnable; Check if cache is enabled
   *
   * @return value of variable (drupal_get)
   */
   public function cacheEnable($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_enable);
  }

  /**\brief set timeout of cache
   *
   * @return mixed value of variable (variable_get)
   */
   public function cacheTimeout($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_lifetime, '1');
  }

  /* \brief implements ITingClientRequestCache::cacheBin
   *
   * @return string; name of cachebin
   */
   public function cacheBin() {
    return 'cache_autocomplete_webservice';
  }
  
  /** end ITingClientRequestCache * */

}
