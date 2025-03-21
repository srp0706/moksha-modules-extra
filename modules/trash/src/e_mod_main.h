#ifndef E_MOD_MAIN_H
#define E_MOD_MAIN_H

#include "config.h"
#ifdef HAVE_GETTEXT
# include <libintl.h>
# define D_(string) dgettext(LOCALEDOMAIN, string)
#else
# define bindtextdomain(domain,dir)
# define bind_textdomain_codeset(domain,codeset)
# define D_(string) (string)
#endif
#define N_(string) (string)

/* Macros used for config file versioning */
/* You can increment the EPOCH value if the old configuration is not
 * compatible anymore, it creates an entire new one.
 * You need to increment GENERATION when you add new values to the
 * configuration file but is not needed to delete the existing conf  */
#define MOD_CONFIG_FILE_EPOCH 0x0001
#define MOD_CONFIG_FILE_GENERATION 0x008d
#define MOD_CONFIG_FILE_VERSION \
   ((MOD_CONFIG_FILE_EPOCH << 16) | MOD_CONFIG_FILE_GENERATION)

/* We create a structure config for our module, and also a config structure
 * for every item element (you can have multiple gadgets for the same module) */

typedef struct _Config Config;
typedef struct _Config_Item Config_Item;

struct _Config 
{
   E_Module *module;
   E_Config_Dialog *cfd;
   Eina_List *conf_items;
   int version;
   int switch1;
   const char *fileman;
};

struct _Config_Item 
{
   const char *id;
   int switch2;   
};

EAPI void *e_modapi_init(E_Module *m);
EAPI int e_modapi_shutdown(E_Module *m);
EAPI int e_modapi_save(E_Module *m);

/* Function for calling the module's Configuration Dialog */
E_Config_Dialog *e_int_config_trash_module(E_Container *con, const char *params);

extern Config *trash_conf;

#endif
