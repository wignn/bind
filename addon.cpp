#include <node.h>

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  // Perbaikan penggunaan NewFromUtf8 dengan argumen tambahan
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world", v8::NewStringType::kNormal)
                                .ToLocalChecked());
}

void Sum(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  double a = 4.4563, b = 5.4563;
  for (int i = 0; i < 1000000; i++) {
    a += b;
  }
  args.GetReturnValue().Set(a);
}

void Initialize(Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "hello", Method);
  NODE_SET_METHOD(exports, "sum", Sum);
}

// Perbaikan nama fungsi init menjadi Initialize
NODE_MODULE(addon, Initialize)
