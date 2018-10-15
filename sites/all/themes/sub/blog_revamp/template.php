<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

 /**
  * Implements template_preprocess_page
  */
 function blog_revamp_preprocess_page(&$variables) {
   drupal_add_css('https://fonts.googleapis.com/css?family=Lobster', 'external');
   drupal_add_css('https://fonts.googleapis.com/css?family=Dancing+Script:400,700', 'external');
   if (drupal_is_front_page()) {
     drupal_add_css(drupal_get_path('theme', 'blog_revamp') . '/css/home.css');
     drupal_add_js(drupal_get_path('theme', 'blog_revamp') . '/js/home.js');
   }
 }
// <link href="https://fonts.googleapis.com/css?family=Lobster" rel="stylesheet">
// font-family: 'Lobster', cursive;
// <link href="https://fonts.googleapis.com/css?family=Dancing+Script:400,700" rel="stylesheet">
// font-family: 'Dancing Script', cursive;
// <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.4.1/css/all.css" integrity="sha384-5sAR7xN1Nv6T6+dT2mhtzEpVJvfS3NScPQTrOxhwjIuvcA67KV2R5Jz6kr4abQsz" crossorigin="anonymous">
