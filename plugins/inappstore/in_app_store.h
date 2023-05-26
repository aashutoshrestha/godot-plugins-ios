#ifndef IN_APP_STORE_H
#define IN_APP_STORE_H

#include "core/version.h"

#if VERSION_MAJOR == 4
#include "core/object/class_db.h"
#else
#include "core/object.h"
#endif

#ifdef __OBJC__
@class GodotProductsDelegate;
@class GodotTransactionsObserver;

typedef GodotProductsDelegate InAppStoreProductDelegate;
typedef GodotTransactionsObserver InAppStoreTransactionObserver;
#else
typedef void InAppStoreProductDelegate;
typedef void InAppStoreTransactionObserver;
#endif

class InAppStore : public Object {

	GDCLASS(InAppStore, Object);

	static InAppStore *instance;
	static void _bind_methods();

	InAppStoreProductDelegate *products_request_delegate;
	InAppStoreTransactionObserver *transactions_observer;

public:
	Error request_product_info(Dictionary p_params);
	Error restore_purchases();
	Error purchase(Dictionary p_params);
	void finish_transaction(String product_id);
	void set_auto_finish_transaction(bool b);
	
	bool if_purchased(String product_id);
	int get_total_purchases();
	void _record_purchase(String product_id);

	static InAppStore *get_singleton();

	InAppStore();
	~InAppStore();
};

#endif
