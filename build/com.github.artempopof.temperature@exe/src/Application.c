/* Application.c generated by valac 0.40.24, the Vala compiler
 * generated from Application.vala, do not modify */

/*
* Copyright (c) 2020 ArtemPopof
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
* Boston, MA 02110-1301 USA
*
* Authored by: Artem Popov <artempopovserg@gmail.com>
*/


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <granite.h>
#include <gio/gio.h>
#include <glib/gi18n-lib.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <stdio.h>


#define TYPE_APPLICATION (application_get_type ())
#define APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_APPLICATION, Application))
#define APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_APPLICATION, ApplicationClass))
#define IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_APPLICATION))
#define IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_APPLICATION))
#define APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_APPLICATION, ApplicationClass))

typedef struct _Application Application;
typedef struct _ApplicationClass ApplicationClass;
typedef struct _ApplicationPrivate ApplicationPrivate;
enum  {
	APPLICATION_0_PROPERTY,
	APPLICATION_NUM_PROPERTIES
};
static GParamSpec* application_properties[APPLICATION_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_thread_unref0(var) ((var == NULL) ? NULL : (var = (g_thread_unref (var), NULL)))

struct _Application {
	GtkApplication parent_instance;
	ApplicationPrivate * priv;
};

struct _ApplicationClass {
	GtkApplicationClass parent_class;
};

struct _ApplicationPrivate {
	GraniteWidgetsWelcome* cpu_temp_label;
};


static gpointer application_parent_class = NULL;

GType application_get_type (void) G_GNUC_CONST;
#define APPLICATION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_APPLICATION, ApplicationPrivate))
static Application* application_new (void);
static Application* application_construct (GType object_type);
static void application_real_activate (GApplication* base);
static GtkWindow* application_create_main_window (Application* self);
static gchar* application_get_cpu_temp (Application* self);
static void application_update_badge (Application* self,
                               gint temp);
static gint application_to_int_temp (Application* self,
                              const gchar* temp_string);
static void application_start_update_cycle (Application* self);
static gchar* application_parse_cpu_temp (Application* self,
                                   const gchar* sensors_output);
static gchar* application_parse_cpu_temp_info (Application* self,
                                        const gchar* cpu_temp_info_line);
static gint application_update_temp (Application* self);
static gpointer _application_update_temp_gthread_func (gpointer self);
gint application_main (gchar** args,
                       int args_length1);
static void application_finalize (GObject * obj);
static void _vala_array_destroy (gpointer array,
                          gint array_length,
                          GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array,
                       gint array_length,
                       GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


static Application*
application_construct (GType object_type)
{
	Application * self = NULL;
#line 26 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	self = (Application*) g_object_new (object_type, "application-id", "com.github.artempopof.temperature", "flags", G_APPLICATION_FLAGS_NONE, NULL);
#line 25 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	return self;
#line 113 "Application.c"
}


static Application*
application_new (void)
{
#line 25 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	return application_construct (TYPE_APPLICATION);
#line 122 "Application.c"
}


static void
application_real_activate (GApplication* base)
{
	Application * self;
	GtkWindow* main_window = NULL;
	GtkWindow* _tmp0_;
	GraniteWidgetsWelcome* how_to_message = NULL;
	GraniteWidgetsWelcome* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	GraniteWidgetsWelcome* _tmp4_;
	GraniteWidgetsWelcome* _tmp5_;
	GraniteWidgetsWelcome* _tmp6_;
	const gchar* _tmp7_;
	const gchar* _tmp8_;
#line 33 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	self = (Application*) base;
#line 34 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp0_ = application_create_main_window (self);
#line 34 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	main_window = _tmp0_;
#line 36 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp1_ = granite_widgets_welcome_new (_ ("Guess boosted frequency"), _ ("Peaking (Bell) EQ filter is being used to boost a certain frequency ra" \
"nge. You need to guess boosted frequency. Use the EQ on/off buttons to" \
" compare the equalized and non equalized sounds."));
#line 36 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_object_ref_sink (_tmp1_);
#line 36 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	how_to_message = _tmp1_;
#line 39 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp2_ = application_get_cpu_temp (self);
#line 39 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp3_ = _tmp2_;
#line 39 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp4_ = granite_widgets_welcome_new (_tmp3_, "");
#line 39 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_object_ref_sink (_tmp4_);
#line 39 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_object_unref0 (self->priv->cpu_temp_label);
#line 39 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	self->priv->cpu_temp_label = _tmp4_;
#line 39 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_free0 (_tmp3_);
#line 42 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp5_ = self->priv->cpu_temp_label;
#line 42 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	gtk_container_add ((GtkContainer*) main_window, (GtkWidget*) _tmp5_);
#line 44 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	gtk_widget_show_all ((GtkWidget*) main_window);
#line 46 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp6_ = self->priv->cpu_temp_label;
#line 46 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp7_ = granite_widgets_welcome_get_title (_tmp6_);
#line 46 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp8_ = _tmp7_;
#line 46 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	application_update_badge (self, application_to_int_temp (self, _tmp8_));
#line 48 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	application_start_update_cycle (self);
#line 33 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_object_unref0 (how_to_message);
#line 33 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_object_unref0 (main_window);
#line 187 "Application.c"
}


static GtkWindow*
application_create_main_window (Application* self)
{
	GtkWindow* result = NULL;
	GtkApplicationWindow* main_window = NULL;
	GtkApplicationWindow* _tmp0_;
	GdkRGBA _tmp1_ = {0};
	GtkCssProvider* _tmp2_;
	GtkCssProvider* _tmp3_;
#line 51 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 52 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp0_ = (GtkApplicationWindow*) gtk_application_window_new ((GtkApplication*) self);
#line 52 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_object_ref_sink (_tmp0_);
#line 52 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	main_window = _tmp0_;
#line 53 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	gtk_window_set_title ((GtkWindow*) main_window, _ ("CPU Temperature"));
#line 56 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_object_set ((GtkWindow*) main_window, "default-width", 450, NULL);
#line 57 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_object_set ((GtkWindow*) main_window, "default-height", 450, NULL);
#line 58 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	gtk_window_set_resizable ((GtkWindow*) main_window, FALSE);
#line 60 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp1_.red = (gdouble) 222;
#line 60 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp1_.green = (gdouble) 22;
#line 60 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp1_.blue = (gdouble) 0;
#line 60 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp1_.alpha = (gdouble) 256;
#line 60 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp2_ = granite_widgets_utils_set_color_primary ((GtkWidget*) main_window, &_tmp1_, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
#line 60 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp3_ = _tmp2_;
#line 60 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_object_unref0 (_tmp3_);
#line 62 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	result = (GtkWindow*) main_window;
#line 62 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	return result;
#line 234 "Application.c"
}


static gchar*
application_get_cpu_temp (Application* self)
{
	gchar* result = NULL;
	gchar* output = NULL;
	gchar* _error_ = NULL;
	gint exit_status = 0;
	gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	GError* _inner_error0_ = NULL;
#line 65 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_spawn_command_line_sync ("sensors", &_tmp0_, &_tmp1_, &_tmp2_, &_inner_error0_);
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_free0 (output);
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	output = _tmp0_;
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_free0 (_error_);
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_error_ = _tmp1_;
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	exit_status = _tmp2_;
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_g_free0 (_error_);
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_g_free0 (output);
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		g_clear_error (&_inner_error0_);
#line 69 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		return NULL;
#line 275 "Application.c"
	}
#line 71 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	if (exit_status != 0) {
#line 279 "Application.c"
		FILE* _tmp3_;
		gchar* _tmp4_;
#line 72 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_tmp3_ = stdout;
#line 72 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		fprintf (_tmp3_, "ERROR OCCURED: %s", _error_);
#line 73 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_tmp4_ = g_strdup ("Can't determine CPU temperature");
#line 73 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		result = _tmp4_;
#line 73 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_g_free0 (_error_);
#line 73 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_g_free0 (output);
#line 73 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		return result;
#line 296 "Application.c"
	} else {
		gchar* _tmp5_;
#line 75 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_tmp5_ = application_parse_cpu_temp (self, output);
#line 75 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		result = _tmp5_;
#line 75 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_g_free0 (_error_);
#line 75 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_g_free0 (output);
#line 75 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		return result;
#line 309 "Application.c"
	}
#line 65 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_free0 (_error_);
#line 65 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_free0 (output);
#line 315 "Application.c"
}


static gboolean
string_contains (const gchar* self,
                 const gchar* needle)
{
	gboolean result = FALSE;
	gchar* _tmp0_;
#line 1475 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, FALSE);
#line 1475 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail (needle != NULL, FALSE);
#line 1476 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp0_ = strstr ((gchar*) self, (gchar*) needle);
#line 1476 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	result = _tmp0_ != NULL;
#line 1476 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	return result;
#line 335 "Application.c"
}


static gchar*
application_parse_cpu_temp (Application* self,
                            const gchar* sensors_output)
{
	gchar* result = NULL;
	gchar** lines = NULL;
	gchar** _tmp0_;
	gchar** _tmp1_;
	gint lines_length1;
	gint _lines_size_;
	gchar** _tmp2_;
	gint _tmp2__length1;
	gchar* _tmp7_;
#line 79 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 79 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_return_val_if_fail (sensors_output != NULL, NULL);
#line 80 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp1_ = _tmp0_ = g_strsplit (sensors_output, "\n", 0);
#line 80 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	lines = _tmp1_;
#line 80 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	lines_length1 = _vala_array_length (_tmp0_);
#line 80 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_lines_size_ = lines_length1;
#line 82 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp2_ = lines;
#line 82 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp2__length1 = lines_length1;
#line 368 "Application.c"
	{
		gchar** line_collection = NULL;
		gint line_collection_length1 = 0;
		gint _line_collection_size_ = 0;
		gint line_it = 0;
#line 82 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		line_collection = _tmp2_;
#line 82 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		line_collection_length1 = _tmp2__length1;
#line 82 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		for (line_it = 0; line_it < line_collection_length1; line_it = line_it + 1) {
#line 380 "Application.c"
			gchar* _tmp3_;
			gchar* line = NULL;
#line 82 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
			_tmp3_ = g_strdup (line_collection[line_it]);
#line 82 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
			line = _tmp3_;
#line 387 "Application.c"
			{
				const gchar* _tmp4_;
#line 83 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
				_tmp4_ = line;
#line 83 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
				if (string_contains (_tmp4_, "Core 0:")) {
#line 394 "Application.c"
					const gchar* _tmp5_;
					gchar* _tmp6_;
#line 84 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
					_tmp5_ = line;
#line 84 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
					_tmp6_ = application_parse_cpu_temp_info (self, _tmp5_);
#line 84 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
					result = _tmp6_;
#line 84 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
					_g_free0 (line);
#line 84 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
					lines = (_vala_array_free (lines, lines_length1, (GDestroyNotify) g_free), NULL);
#line 84 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
					return result;
#line 409 "Application.c"
				}
#line 82 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
				_g_free0 (line);
#line 413 "Application.c"
			}
		}
	}
#line 88 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp7_ = g_strdup ("Can't determine CPU temperature");
#line 88 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	result = _tmp7_;
#line 88 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	lines = (_vala_array_free (lines, lines_length1, (GDestroyNotify) g_free), NULL);
#line 88 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	return result;
#line 425 "Application.c"
}


static gchar*
application_parse_cpu_temp_info (Application* self,
                                 const gchar* cpu_temp_info_line)
{
	gchar* result = NULL;
	gchar** lines = NULL;
	gchar** _tmp0_;
	gchar** _tmp1_;
	gint lines_length1;
	gint _lines_size_;
	const gchar* _tmp2_;
	gchar** _tmp3_;
	gchar** _tmp4_;
	gchar** _tmp5_;
	gint _tmp5__length1;
	const gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
#line 91 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 91 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_return_val_if_fail (cpu_temp_info_line != NULL, NULL);
#line 92 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp1_ = _tmp0_ = g_strsplit (cpu_temp_info_line, "+", 0);
#line 92 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	lines = _tmp1_;
#line 92 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	lines_length1 = _vala_array_length (_tmp0_);
#line 92 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_lines_size_ = lines_length1;
#line 94 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp2_ = lines[1];
#line 94 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp4_ = _tmp3_ = g_strsplit (_tmp2_, " ", 0);
#line 94 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp5_ = _tmp4_;
#line 94 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp5__length1 = _vala_array_length (_tmp3_);
#line 94 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp6_ = _tmp5_[0];
#line 94 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp7_ = g_strconcat ("+", _tmp6_, NULL);
#line 94 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp8_ = _tmp7_;
#line 94 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp5_ = (_vala_array_free (_tmp5_, _tmp5__length1, (GDestroyNotify) g_free), NULL);
#line 94 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	result = _tmp8_;
#line 94 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	lines = (_vala_array_free (lines, lines_length1, (GDestroyNotify) g_free), NULL);
#line 94 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	return result;
#line 481 "Application.c"
}


static glong
string_strnlen (gchar* str,
                glong maxlen)
{
	glong result = 0L;
	gchar* end = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
#line 1392 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp0_ = memchr (str, 0, (gsize) maxlen);
#line 1392 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	end = _tmp0_;
#line 1393 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp1_ = end;
#line 1393 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (_tmp1_ == NULL) {
#line 1394 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		result = maxlen;
#line 1394 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		return result;
#line 505 "Application.c"
	} else {
		gchar* _tmp2_;
#line 1396 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp2_ = end;
#line 1396 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		result = (glong) (_tmp2_ - str);
#line 1396 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		return result;
#line 514 "Application.c"
	}
}


static gchar*
string_substring (const gchar* self,
                  glong offset,
                  glong len)
{
	gchar* result = NULL;
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	glong _tmp6_;
	gchar* _tmp7_;
#line 1403 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1405 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (offset >= ((glong) 0)) {
#line 1405 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp0_ = len >= ((glong) 0);
#line 535 "Application.c"
	} else {
#line 1405 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp0_ = FALSE;
#line 539 "Application.c"
	}
#line 1405 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (_tmp0_) {
#line 1407 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		string_length = string_strnlen ((gchar*) self, offset + len);
#line 545 "Application.c"
	} else {
		gint _tmp1_;
		gint _tmp2_;
#line 1409 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp1_ = strlen (self);
#line 1409 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp2_ = _tmp1_;
#line 1409 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		string_length = (glong) _tmp2_;
#line 555 "Application.c"
	}
#line 1412 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (offset < ((glong) 0)) {
#line 559 "Application.c"
		glong _tmp3_;
#line 1413 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp3_ = string_length;
#line 1413 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		offset = _tmp3_ + offset;
#line 1414 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		g_return_val_if_fail (offset >= ((glong) 0), NULL);
#line 567 "Application.c"
	} else {
		glong _tmp4_;
#line 1416 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp4_ = string_length;
#line 1416 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		g_return_val_if_fail (offset <= _tmp4_, NULL);
#line 574 "Application.c"
	}
#line 1418 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (len < ((glong) 0)) {
#line 578 "Application.c"
		glong _tmp5_;
#line 1419 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp5_ = string_length;
#line 1419 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		len = _tmp5_ - offset;
#line 584 "Application.c"
	}
#line 1421 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp6_ = string_length;
#line 1421 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail ((offset + len) <= _tmp6_, NULL);
#line 1422 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp7_ = g_strndup (((gchar*) self) + offset, (gsize) len);
#line 1422 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	result = _tmp7_;
#line 1422 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	return result;
#line 596 "Application.c"
}


static gint
application_to_int_temp (Application* self,
                         const gchar* temp_string)
{
	gint result = 0;
	gchar* int_string = NULL;
	gint _tmp0_;
	gint _tmp1_;
	gchar* _tmp2_;
	FILE* _tmp3_;
	gchar** _tmp4_;
	gchar** _tmp5_;
	gchar** _tmp6_;
	gint _tmp6__length1;
	const gchar* _tmp7_;
	gint _tmp8_;
#line 97 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_return_val_if_fail (self != NULL, 0);
#line 97 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_return_val_if_fail (temp_string != NULL, 0);
#line 98 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp0_ = strlen (temp_string);
#line 98 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp1_ = _tmp0_;
#line 98 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp2_ = string_substring (temp_string, (glong) 1, (glong) (_tmp1_ - 4));
#line 98 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	int_string = _tmp2_;
#line 99 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp3_ = stdout;
#line 99 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	fprintf (_tmp3_, "TEMP %s\n", int_string);
#line 101 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp5_ = _tmp4_ = g_strsplit (int_string, ".", 0);
#line 101 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp6_ = _tmp5_;
#line 101 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp6__length1 = _vala_array_length (_tmp4_);
#line 101 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp7_ = _tmp6_[0];
#line 101 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp8_ = atoi (_tmp7_);
#line 101 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp6_ = (_vala_array_free (_tmp6_, _tmp6__length1, (GDestroyNotify) g_free), NULL);
#line 101 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	result = _tmp8_;
#line 101 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_free0 (int_string);
#line 101 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	return result;
#line 650 "Application.c"
}


static void
application_update_badge (Application* self,
                          gint temp)
{
	FILE* _tmp0_;
#line 104 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_return_if_fail (self != NULL);
#line 105 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp0_ = stdout;
#line 105 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	fprintf (_tmp0_, "\nupdating badge with value %d", temp);
#line 106 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	granite_services_application_set_badge_visible (TRUE, NULL, NULL);
#line 107 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	granite_services_application_set_badge ((gint64) temp, NULL, NULL);
#line 669 "Application.c"
}


static gpointer
_application_update_temp_gthread_func (gpointer self)
{
	gpointer result;
	result = (gpointer) ((gintptr) application_update_temp ((Application*) self));
#line 111 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_object_unref (self);
#line 111 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	return result;
#line 682 "Application.c"
}


static void
application_start_update_cycle (Application* self)
{
	GThread* thread = NULL;
	GThread* _tmp0_;
#line 110 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_return_if_fail (self != NULL);
#line 111 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp0_ = g_thread_new ("update_temp_thread", _application_update_temp_gthread_func, g_object_ref (self));
#line 111 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	thread = _tmp0_;
#line 110 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_thread_unref0 (thread);
#line 699 "Application.c"
}


static gint
application_update_temp (Application* self)
{
	gint result = 0;
	FILE* _tmp0_;
#line 114 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_return_val_if_fail (self != NULL, 0);
#line 115 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp0_ = stdout;
#line 115 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	fprintf (_tmp0_, "start updating temp");
#line 117 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	while (TRUE) {
#line 716 "Application.c"
		GraniteWidgetsWelcome* _tmp1_;
		const gchar* _tmp2_;
		const gchar* _tmp3_;
		GraniteWidgetsWelcome* _tmp4_;
		gchar* _tmp5_;
		gchar* _tmp6_;
#line 118 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_tmp1_ = self->priv->cpu_temp_label;
#line 118 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_tmp2_ = granite_widgets_welcome_get_title (_tmp1_);
#line 118 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_tmp3_ = _tmp2_;
#line 118 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		application_update_badge (self, application_to_int_temp (self, _tmp3_));
#line 119 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		g_usleep ((gulong) 1000000);
#line 121 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_tmp4_ = self->priv->cpu_temp_label;
#line 121 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_tmp5_ = application_get_cpu_temp (self);
#line 121 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_tmp6_ = _tmp5_;
#line 121 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		granite_widgets_welcome_set_title (_tmp4_, _tmp6_);
#line 121 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
		_g_free0 (_tmp6_);
#line 743 "Application.c"
	}
#line 124 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	result = 0;
#line 124 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	return result;
#line 114 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	return result;
#line 751 "Application.c"
}


gint
application_main (gchar** args,
                  int args_length1)
{
	gint result = 0;
	Application* app = NULL;
	Application* _tmp0_;
#line 128 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_tmp0_ = application_new ();
#line 128 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	app = _tmp0_;
#line 129 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	result = g_application_run ((GApplication*) app, args_length1, args);
#line 129 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_object_unref0 (app);
#line 129 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	return result;
#line 772 "Application.c"
}


int
main (int argc,
      char ** argv)
{
#line 127 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	return application_main (argv, argc);
#line 782 "Application.c"
}


static void
application_class_init (ApplicationClass * klass)
{
#line 21 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	application_parent_class = g_type_class_peek_parent (klass);
#line 21 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	g_type_class_add_private (klass, sizeof (ApplicationPrivate));
#line 21 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	((GApplicationClass *) klass)->activate = (void (*) (GApplication*)) application_real_activate;
#line 21 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	G_OBJECT_CLASS (klass)->finalize = application_finalize;
#line 797 "Application.c"
}


static void
application_instance_init (Application * self)
{
#line 21 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	self->priv = APPLICATION_GET_PRIVATE (self);
#line 806 "Application.c"
}


static void
application_finalize (GObject * obj)
{
	Application * self;
#line 21 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_APPLICATION, Application);
#line 23 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	_g_object_unref0 (self->priv->cpu_temp_label);
#line 21 "/home/artem/Documents/GithubProjects/Temperature/src/Application.vala"
	G_OBJECT_CLASS (application_parent_class)->finalize (obj);
#line 820 "Application.c"
}


GType
application_get_type (void)
{
	static volatile gsize application_type_id__volatile = 0;
	if (g_once_init_enter (&application_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ApplicationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) application_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Application), 0, (GInstanceInitFunc) application_instance_init, NULL };
		GType application_type_id;
		application_type_id = g_type_register_static (gtk_application_get_type (), "Application", &g_define_type_info, 0);
		g_once_init_leave (&application_type_id__volatile, application_type_id);
	}
	return application_type_id__volatile;
}


static void
_vala_array_destroy (gpointer array,
                     gint array_length,
                     GDestroyNotify destroy_func)
{
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void
_vala_array_free (gpointer array,
                  gint array_length,
                  GDestroyNotify destroy_func)
{
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint
_vala_array_length (gpointer array)
{
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}


