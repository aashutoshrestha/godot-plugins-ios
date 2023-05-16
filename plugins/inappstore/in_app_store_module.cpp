#include "in_app_store_module.h"

#include "core/version.h"

#if VERSION_MAJOR == 4
#include "core/config/engine.h"
#else
#include "core/engine.h"
#endif

#include "in_app_store.h"

InAppStore *store_kit;

void register_inappstore_types() {
	store_kit = memnew(InAppStore);
	Engine::get_singleton()->add_singleton(Engine::Singleton("InAppStore", store_kit));
}

void unregister_inappstore_types() {
	if (store_kit) {
		memdelete(store_kit);
	}
}
