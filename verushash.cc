#include <node_api.h>
#include <node_buffer.h>
#include <vector>

#include "crypto/verus_hash.h"
#include "sodium.h"

CVerusHash* vh;
CVerusHashV2* vh2;
CVerusHashV2* vh2b1;
CVerusHashV2* vh2b2;

bool initialized = false;

void initialize() {
    if (!initialized) {
        CVerusHash::init();
        CVerusHashV2::init();
        vh = new CVerusHash();
        vh2 = new CVerusHashV2(SOLUTION_VERUSHHASH_V2);
        vh2b1 = new CVerusHashV2(SOLUTION_VERUSHHASH_V2_1);
        vh2b2 = new CVerusHashV2(SOLUTION_VERUSHHASH_V2_2);
        initialized = true;
    }
}

napi_value verusInit(napi_env env, napi_callback_info info) {
    initialize();
    napi_value thisArg;
    napi_get_cb_info(env, info, nullptr, nullptr, &thisArg, nullptr);
    return thisArg;
}

napi_value verusHash(napi_env env, napi_callback_info info) {
    // ... verusHash implementation ...
}

napi_value verusHashV2(napi_env env, napi_callback_info info) {
    // ... verusHashV2 implementation ...
}

napi_value verusHashV2b(napi_env env, napi_callback_info info) {
    // ... verusHashV2b implementation ...
}

napi_value verusHashV2b1(napi_env env, napi_callback_info info) {
    // ... verusHashV2b1 implementation ...
}

napi_value verusHashV2b2(napi_env env, napi_callback_info info) {
    // ... verusHashV2b2 implementation ...
}

napi_value Init(napi_env env, napi_value exports) {
    napi_status status;
    napi_value fn;

    status = napi_create_function(env, "init", NAPI_AUTO_LENGTH, verusInit, nullptr, &fn);
    status = napi_set_named_property(env, exports, "init", fn);

    // Create and set other functions: hash, hash2, hash2b, hash2b1, hash2b2
    // ...

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
