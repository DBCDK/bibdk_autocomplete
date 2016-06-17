(function ($) {

  /**
   *
   */
  Drupal.behaviors.bibdk_autocomplete_scan_next = {
    attach: function (context, settings) {
      $('#search-block-form input[data-autocomplete="scan"]').each(function (context) {
        bibdk_autocomplete_scan_next($(this));
      });
    }
  };

  /**
   * add "next 10" block in autocomplete dropdown, if scan function is selected
   */
  bibdk_autocomplete_scan_next = function ($obj) {
    var suffix = document.createElement("p");
    suffix.innerHTML = "Next 10";
    $obj.parent().find('span.element-invisible').append(suffix);
    //
  };

})(jQuery);