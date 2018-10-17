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
   drupal_add_css('https://fonts.googleapis.com/css?family=Montserrat:400,500,600,800', 'external');

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


/**
 * Implements template_preprocess_node
 */
function blog_revamp_preprocess_node(&$variables) {

  if(arg(0) == 'node' && is_numeric(arg(1)) && arg(1) > 0) {
    $nid = arg(1);
    $node = node_load($nid);
    if ($node->type == 'create_blog') {
      $output = '<div class="icons"><div class="social-media-icons"><p class="share-text">Share On:</p>';
      $theme_path = path_to_theme();
      drupal_add_css($theme_path . '/stylesheets/node-blogs.css', 'file');

      GLOBAL $base_url;
      GLOBAL $base_path;
      $current_url = $base_url . $base_path . drupal_get_path_alias(current_path());

      // facebook
      $output .= '<a class="fa fa-facebook" href = "http://www.facebook.com/sharer.php?u=' . $current_url . '&hashtag=%23' . $node->title . '"></a>';

      // Twitter.
      $output .= '<a class="fa fa-twitter" href=https://twitter.com/intent/tweet?&url=' . $current_url . '&hashtags=' . $node->title . '></a></div></div> ';

      $variables['content']['field_social_media_icons'][0]['#markup'] = $output;
    }
  }
}

/**
 * Implements template_preprocess_views_view
 */
function blog_revamp_preprocess_views_view(&$vars) {
  if (arg(0) == 'user' && arg(1) > 0) {
    $userid = arg(1);
  }
  else {
    $userid = 0;
  }

  $path = current_path();
  $theme_path = path_to_theme();
  switch ($path) {
    case 'techsection':
    case 'nontechsection':
    case 'its-show-time':
      drupal_add_css($theme_path . '/stylesheets/education-section.css', 'file');
    break;
    case 'myprofile':
      drupal_add_css($theme_path . '/stylesheets/my-profile.css', 'file');
      drupal_add_css($theme_path . '/stylesheets/node-blogs.css', 'file');
    break;
    case 'user/' . $userid :
      drupal_add_css($theme_path . '/stylesheets/user-dashboard.css', 'file');
    break;
    case 'myprojects':
      drupal_add_css($theme_path . '/stylesheets/my-projects.css', 'file');
    break;
    case 'blogs':
      drupal_add_css($theme_path . '/stylesheets/blogs.css', 'file');
    break;
  }
}
