/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: google/cloud/dialogflow/v2beta1/webhook.proto */

#ifndef PROTOBUF_C_google_2fcloud_2fdialogflow_2fv2beta1_2fwebhook_2eproto__INCLUDED
#define PROTOBUF_C_google_2fcloud_2fdialogflow_2fv2beta1_2fwebhook_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003000 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "annotations.pb-c.h"
#include "context.pb-c.h"
#include "intent.pb-c.h"
#include "session.pb-c.h"
#include "struct.pb-c.h"

typedef struct _Google__Cloud__Dialogflow__V2beta1__WebhookRequest Google__Cloud__Dialogflow__V2beta1__WebhookRequest;
typedef struct _Google__Cloud__Dialogflow__V2beta1__WebhookResponse Google__Cloud__Dialogflow__V2beta1__WebhookResponse;
typedef struct _Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest;


/* --- enums --- */


/* --- messages --- */

/*
 * The request message for a webhook call.
 */
struct  _Google__Cloud__Dialogflow__V2beta1__WebhookRequest
{
  ProtobufCMessage base;
  /*
   * The unique identifier of detectIntent request session.
   * Can be used to identify end-user inside webhook implementation.
   * Format: `projects/<Project ID>/agent/sessions/<Session ID>`.
   */
  char *session;
  /*
   * The unique identifier of the response. Contains the same value as
   * `[Streaming]DetectIntentResponse.response_id`.
   */
  char *response_id;
  /*
   * The result of the conversational query or event processing. Contains the
   * same value as `[Streaming]DetectIntentResponse.query_result`.
   */
  Google__Cloud__Dialogflow__V2beta1__QueryResult *query_result;
  /*
   * Alternative query results from KnowledgeService.
   */
  size_t n_alternative_query_results;
  Google__Cloud__Dialogflow__V2beta1__QueryResult **alternative_query_results;
  /*
   * Optional. The contents of the original request that was passed to
   * `[Streaming]DetectIntent` call.
   */
  Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest *original_detect_intent_request;
};
#define GOOGLE__CLOUD__DIALOGFLOW__V2BETA1__WEBHOOK_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&google__cloud__dialogflow__v2beta1__webhook_request__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, NULL, 0,NULL, NULL }


/*
 * The response message for a webhook call.
 */
struct  _Google__Cloud__Dialogflow__V2beta1__WebhookResponse
{
  ProtobufCMessage base;
  /*
   * Optional. The text to be shown on the screen. This value is passed directly
   * to `QueryResult.fulfillment_text`.
   */
  char *fulfillment_text;
  /*
   * Optional. The collection of rich messages to present to the user. This
   * value is passed directly to `QueryResult.fulfillment_messages`.
   */
  size_t n_fulfillment_messages;
  Google__Cloud__Dialogflow__V2beta1__Intent__Message **fulfillment_messages;
  /*
   * Optional. This value is passed directly to `QueryResult.webhook_source`.
   */
  char *source;
  /*
   * Optional. This value is passed directly to `QueryResult.webhook_payload`.
   * See the related `fulfillment_messages[i].payload field`, which may be used
   * as an alternative to this field.
   * This field can be used for Actions on Google responses.
   * It should have a structure similar to the JSON message shown here. For more
   * information, see
   * [Actions on Google Webhook
   * Format](https://developers.google.com/actions/dialogflow/webhook)
   * <pre>{
   *   "google": {
   *     "expectUserResponse": true,
   *     "richResponse": {
   *       "items": [
   *         {
   *           "simpleResponse": {
   *             "textToSpeech": "this is a simple response"
   *           }
   *         }
   *       ]
   *     }
   *   }
   * }</pre>
   */
  Google__Protobuf__Struct *payload;
  /*
   * Optional. The collection of output contexts. This value is passed directly
   * to `QueryResult.output_contexts`.
   */
  size_t n_output_contexts;
  Google__Cloud__Dialogflow__V2beta1__Context **output_contexts;
  /*
   * Optional. Makes the platform immediately invoke another `DetectIntent` call
   * internally with the specified event as input.
   */
  Google__Cloud__Dialogflow__V2beta1__EventInput *followup_event_input;
  /*
   * Optional. Indicates that this intent ends an interaction. Some integrations
   * (e.g., Actions on Google or Dialogflow phone gateway) use this information
   * to close interaction with an end user. Default is false.
   */
  protobuf_c_boolean end_interaction;
};
#define GOOGLE__CLOUD__DIALOGFLOW__V2BETA1__WEBHOOK_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&google__cloud__dialogflow__v2beta1__webhook_response__descriptor) \
    , (char *)protobuf_c_empty_string, 0,NULL, (char *)protobuf_c_empty_string, NULL, 0,NULL, NULL, 0 }


/*
 * Represents the contents of the original request that was passed to
 * the `[Streaming]DetectIntent` call.
 */
struct  _Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest
{
  ProtobufCMessage base;
  /*
   * The source of this request, e.g., `google`, `facebook`, `slack`. It is set
   * by Dialogflow-owned servers.
   */
  char *source;
  /*
   * Optional. The version of the protocol used for this request.
   * This field is AoG-specific.
   */
  char *version;
  /*
   * Optional. This field is set to the value of `QueryParameters.payload` field
   * passed in the request.
   * This field is used for the telephony gateway. It should have a
   * structure similar to this JSON message:
   * <pre>{
   *  "telephony": {
   *    "caller_id": "+18558363987"
   *  }
   * }</pre>
   * Note: The caller ID field (`caller_id`) will be in
   * [E.164 format](https://en.wikipedia.org/wiki/E.164) and is only supported
   * for Enterprise Edition and not for Standard Edition agents. When the
   * telephony gateway is used with a standard tier agent the `caller_id` field
   * above will have a value of `REDACTED_IN_STANDARD_TIER_AGENT`.
   */
  Google__Protobuf__Struct *payload;
};
#define GOOGLE__CLOUD__DIALOGFLOW__V2BETA1__ORIGINAL_DETECT_INTENT_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&google__cloud__dialogflow__v2beta1__original_detect_intent_request__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, NULL }


/* Google__Cloud__Dialogflow__V2beta1__WebhookRequest methods */
void   google__cloud__dialogflow__v2beta1__webhook_request__init
                     (Google__Cloud__Dialogflow__V2beta1__WebhookRequest         *message);
size_t google__cloud__dialogflow__v2beta1__webhook_request__get_packed_size
                     (const Google__Cloud__Dialogflow__V2beta1__WebhookRequest   *message);
size_t google__cloud__dialogflow__v2beta1__webhook_request__pack
                     (const Google__Cloud__Dialogflow__V2beta1__WebhookRequest   *message,
                      uint8_t             *out);
size_t google__cloud__dialogflow__v2beta1__webhook_request__pack_to_buffer
                     (const Google__Cloud__Dialogflow__V2beta1__WebhookRequest   *message,
                      ProtobufCBuffer     *buffer);
Google__Cloud__Dialogflow__V2beta1__WebhookRequest *
       google__cloud__dialogflow__v2beta1__webhook_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   google__cloud__dialogflow__v2beta1__webhook_request__free_unpacked
                     (Google__Cloud__Dialogflow__V2beta1__WebhookRequest *message,
                      ProtobufCAllocator *allocator);
/* Google__Cloud__Dialogflow__V2beta1__WebhookResponse methods */
void   google__cloud__dialogflow__v2beta1__webhook_response__init
                     (Google__Cloud__Dialogflow__V2beta1__WebhookResponse         *message);
size_t google__cloud__dialogflow__v2beta1__webhook_response__get_packed_size
                     (const Google__Cloud__Dialogflow__V2beta1__WebhookResponse   *message);
size_t google__cloud__dialogflow__v2beta1__webhook_response__pack
                     (const Google__Cloud__Dialogflow__V2beta1__WebhookResponse   *message,
                      uint8_t             *out);
size_t google__cloud__dialogflow__v2beta1__webhook_response__pack_to_buffer
                     (const Google__Cloud__Dialogflow__V2beta1__WebhookResponse   *message,
                      ProtobufCBuffer     *buffer);
Google__Cloud__Dialogflow__V2beta1__WebhookResponse *
       google__cloud__dialogflow__v2beta1__webhook_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   google__cloud__dialogflow__v2beta1__webhook_response__free_unpacked
                     (Google__Cloud__Dialogflow__V2beta1__WebhookResponse *message,
                      ProtobufCAllocator *allocator);
/* Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest methods */
void   google__cloud__dialogflow__v2beta1__original_detect_intent_request__init
                     (Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest         *message);
size_t google__cloud__dialogflow__v2beta1__original_detect_intent_request__get_packed_size
                     (const Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest   *message);
size_t google__cloud__dialogflow__v2beta1__original_detect_intent_request__pack
                     (const Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest   *message,
                      uint8_t             *out);
size_t google__cloud__dialogflow__v2beta1__original_detect_intent_request__pack_to_buffer
                     (const Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest   *message,
                      ProtobufCBuffer     *buffer);
Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest *
       google__cloud__dialogflow__v2beta1__original_detect_intent_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   google__cloud__dialogflow__v2beta1__original_detect_intent_request__free_unpacked
                     (Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Google__Cloud__Dialogflow__V2beta1__WebhookRequest_Closure)
                 (const Google__Cloud__Dialogflow__V2beta1__WebhookRequest *message,
                  void *closure_data);
typedef void (*Google__Cloud__Dialogflow__V2beta1__WebhookResponse_Closure)
                 (const Google__Cloud__Dialogflow__V2beta1__WebhookResponse *message,
                  void *closure_data);
typedef void (*Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest_Closure)
                 (const Google__Cloud__Dialogflow__V2beta1__OriginalDetectIntentRequest *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor google__cloud__dialogflow__v2beta1__webhook_request__descriptor;
extern const ProtobufCMessageDescriptor google__cloud__dialogflow__v2beta1__webhook_response__descriptor;
extern const ProtobufCMessageDescriptor google__cloud__dialogflow__v2beta1__original_detect_intent_request__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_google_2fcloud_2fdialogflow_2fv2beta1_2fwebhook_2eproto__INCLUDED */
