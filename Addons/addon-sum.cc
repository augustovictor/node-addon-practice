#include <node.h>

void Sum(const v8::FunctionCallbackInfo<v8::Value>& args) { // Gives us access to the arguments given in a js file
    v8::Isolate* isolate = args.GetIsolate(); // Access to the scope of js file

    int i;
    double a = 3.1415926;
    double b = 2.718;

    for(i = 0; i < 10000000; i++) {
        a += b;
    }

    auto total = v8::Number::New(isolate, a); // Parse the value to v8 number type
    args.GetReturnValue().Set(total); // Return value to js file
}

// Like module.exports
void Init(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "sum", Sum);
}

NODE_MODULE(addon, Init);