/*
 * @file implementation of Radio Button design
 */
(function($) {
   Drupal.behaviors.homejs = {
    attach: function (context, settings) {
  $('a').click({
     $('a').attr("target","_blank");
  });
  }
};})(jQuery);
