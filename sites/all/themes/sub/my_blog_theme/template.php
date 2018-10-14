<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

/**
 * Implements template_preprocess_node
 */
function my_blog_theme_preprocess_node(&$variables) {

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
function my_blog_theme_preprocess_views_view(&$vars) {
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

/**
 * Implements template_preprocess_page
 */
function my_blog_theme_preprocess_page(&$variables) {
  drupal_add_css('https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css', 'external');
  $theme_path = path_to_theme();
  drupal_add_css($theme_path . '/stylesheets/basic_layout.css', 'file');
  $path = current_path();
  switch ($path) {
    case 'node':
    case 'myprojects':
    case 'myprofile':
    case 'user/login':
    case 'user/register':
    case 'user/password':
      drupal_add_js($theme_path . '/js/particles.js', array('scope' => 'footer'));
      drupal_add_js($theme_path . '/js/home.js', array('scope' => 'footer'));
    break;
  }

  if (user_is_logged_in()) {
    $variables['page']['footer']['webform_client-block-29']['#block']->subject = "Contact Mohit Bansal";
  }
  else {
    $variables['page']['footer']['webform_client-block-29']['#block']->subject = "Contact Me";
  }
}

/**
 * Implements template_preprocess_html
 */
function my_blog_theme_preprocess_html(&$variables) {
  $variables['body_attributes_array']['id'] = 'particles-js';
}

/**
 * Implements hook_page_build()
 */
// function my_blog_theme_page_build(&$page) {
//   kpr($page);
//   watchdog('page_buid', print_r($page, TRUE));
// }

// function my_blog_theme_node_insert($node) {
//   watchdog('template', print_r(user_is_logged_in(), TRUE));
//   dpm($node);
// }

// function my_blog_theme_menu_alter(&$items) {
  // dpm("Hello");
  // if (user_is_logged_in() == TRUE) {
    // watchdog('template', print_r(user_is_logged_in(), TRUE));
    // $items['user/login']['access callback'] = FALSE;
  // }
  // else {
    // $items['user/login']['access callback'] = TRUE;
  // }
// }

