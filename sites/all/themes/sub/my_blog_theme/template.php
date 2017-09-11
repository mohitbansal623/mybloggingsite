<?php
/**
 * @file
 * The primary PHP file for the Drupal Bootstrap base theme.
 *
 * This file should only contain light helper functions and point to stubs in
 * other files containing more complex functions.
 *
 * The stubs should point to files within the `./includes` folder named after
 * the function itself minus the theme prefix. If the stub contains a group of
 * functions, then please organize them so they are related in some way and name
 * the file appropriately to at least hint at what it contains.
 *
 * All [pre]process functions, theme functions and template files lives inside
 * the `./templates` folder. This is a highly automated and complex system
 * designed to only load the necessary files when a given theme hook is invoked.
 *
 * Visit this project's official documentation site, http://drupal-bootstrap.org
 * or the markdown files inside the `./docs` folder.
 *
 * @see _bootstrap_theme()
 */

/**
 * Include common functions used through out theme.
 */
// include_once dirname(__FILE__) . '/includes/common.inc';

/**
 * Include any deprecated functions.
 */
// bootstrap_include('bootstrap', 'includes/deprecated.inc');

/**
 * Implements hook_theme().
 *
 * Register theme hook implementations.
 *
 * The implementations declared by this hook have two purposes: either they
 * specify how a particular render array is to be rendered as HTML (this is
 * usually the case if the theme function is assigned to the render array's
 * #theme property), or they return the HTML that should be returned by an
 * invocation of theme().
 *
 * @see _bootstrap_theme()
 */
function my_blog_theme_theme(&$existing, $type, $theme, $path) {
  // dpm($theme);
  // bootstrap_include($theme, 'includes/registry.inc');
  bootstrap_include('bootstrap', 'includes/registry.inc');

  return _bootstrap_theme($existing, $type, $theme, $path);
}

function my_blog_theme_preprocess_node(&$variables) {

  if(arg(0) == 'node' && is_numeric(arg(1)) && arg(1) > 0) {
    $nid = arg(1);
    $node = node_load($nid);
    if ($node->type == 'create_blog') {
      drupal_add_css('https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css', 'external');
      $output = '<div class="icons"><div class="social-media-icons"><p class="share-text">Share On:</p>';
      $theme_path = path_to_theme();
      drupal_add_css($theme_path . '/stylesheets/node-blogs.css', 'file');
      // facebook
      $output .= '<a class="fa fa-facebook" href = "http://www.facebook.com/sharer.php?u=MYBLOG&hashtag=%23MyBlog"></a>';

      // Twitter.
      $output .= '<a class="fa fa-twitter" href=https://twitter.com/intent/tweet?text=MyBlog&hashtags=MyBlog></a></div></div> ';

      $variables['content']['field_social_media_icons'][0]['#markup'] = $output;
    }
  }
}

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
    case 'tech-section':
    case 'nontech-section':
      drupal_add_css($theme_path . '/stylesheets/education-section.css', 'file');
    break;
    case 'my-profile':
      drupal_add_css($theme_path . '/stylesheets/my-profile.css', 'file');
    break;
    case 'user/' . $userid :
      drupal_add_css($theme_path . '/stylesheets/user-dashboard.css', 'file');
    break;
    case 'my-projects':
      drupal_add_css($theme_path . '/stylesheets/my-projects.css', 'file');
    break;
  }
}

function my_blog_theme_preprocess_page(&$variables) {
  $theme_path = path_to_theme();
  drupal_add_css($theme_path . '/stylesheets/basic_layout.css', 'file');
  if (user_is_logged_in()) {
    $variables['page']['footer']['webform_client-block-29']['#block']->subject = "Contact Mohit Bansal";
  }
  else {
    $variables['page']['footer']['webform_client-block-29']['#block']->subject = "Contact Me";
  }
}

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




/**
 * Clear any previously set element_info() static cache.
 *
 * If element_info() was invoked before the theme was fully initialized, this
 * can cause the theme's alter hook to not be invoked.
 *
 * @see https://www.drupal.org/node/2351731
 */
drupal_static_reset('element_info');

/**
 * Declare various hook_*_alter() hooks.
 *
 * hook_*_alter() implementations must live (via include) inside this file so
 * they are properly detected when drupal_alter() is invoked.
 */
bootstrap_include('bootstrap', 'includes/alter.inc');
