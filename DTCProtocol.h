
// Data and Trading Communications Protocol (DTC Protocol)

// This protocol is in the public domain and freely usable by anyone.

// Documentation: http://www.sierrachart.com/index.php?file=doc/doc_DTCMessageDocumentation.php

// The byte ordering is little endian.

// DTC C API
#ifndef __DTC_PROTOCOL_H__
#define __DTC_PROTOCOL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#pragma pack(8)

// DTC protocol version
#define CURRENT_VERSION                     4
//Version history:
//4: converting quantities from integers to floats for trading.

// Text string lengths. The protocol is intended to be updated to support variable length strings making these irrelevant at that time.
#define SYMBOL_LENGTH                       64
#define EXCHANGE_LENGTH                     16
#define UNDERLYING_SYMBOL_LENGTH            32
#define SYMBOL_DESCRIPTION_LENGTH           48
#define EXCHANGE_DESCRIPTION_LENGTH         48
#define ORDER_ID_LENGTH                     32
#define TRADE_ACCOUNT_LENGTH                32
#define TEXT_DESCRIPTION_LENGTH             96
#define TEXT_MESSAGE_LENGTH                 256

//----Message types----

// Authentication and connection monitoring
#define LOGON_REQUEST                               1
#define LOGON_RESPONSE                              2
#define HEARTBEAT                                   3
#define DISCONNECT_FROM_SERVER_NO_RECONNECT         4
#define LOGOFF_REQUEST                              5

// Market data
#define MARKET_DATA_FEED_STATUS                     100
#define MARKET_DATA_REQUEST                         101
#define MARKET_DEPTH_REQUEST                        102
#define MARKET_DATA_REJECT                          103
#define MARKET_DATA_SNAPSHOT                        104
#define MARKET_DEPTH_FULL_UPDATE_20                 105
#define MARKET_DEPTH_INCREMENTAL_UPDATE             106
#define TRADE_INCREMENTAL_UPDATE                    107
#define QUOTE_INCREMENTAL_UPDATE                    108
#define FUNDAMENTAL_DATA_RESPONSE                   110

#define TRADE_INCREMENTAL_UPDATE_COMPACT            112
#define DAILY_VOLUME_INCREMENTAL_UPDATE             113
#define DAILY_HIGH_INCREMENTAL_UPDATE               114
#define DAILY_LOW_INCREMENTAL_UPDATE                115
#define MARKET_DATA_FEED_SYMBOL_STATUS              116
#define QUOTE_INCREMENTAL_UPDATE_COMPACT            117
#define MARKET_DEPTH_INCREMENTAL_UPDATE_COMPACT     118
#define SETTLEMENT_INCREMENTAL_UPDATE               119
#define DAILY_OPEN_INCREMENTAL_UPDATE               120
#define MARKET_DEPTH_REJECT                         121
#define MARKET_DEPTH_SNAPSHOT_LEVEL                 122
#define MARKET_DEPTH_FULL_UPDATE_10                 123
#define OPEN_INTEREST_INCREMENTAL_UPDATE            124


// Order entry and modification
#define SUBMIT_NEW_SINGLE_ORDER                     200
#define SUBMIT_NEW_OCO_ORDER                        201
#define CANCEL_REPLACE_ORDER                        202
#define CANCEL_ORDER                                203

// Trading related
#define OPEN_ORDERS_REQUEST                         300
#define ORDER_UPDATE_REPORT                         301
#define OPEN_ORDERS_REQUEST_REJECT                  302
#define HISTORICAL_ORDER_FILLS_REQUEST              303
#define HISTORICAL_ORDER_FILL_REPORT                304
#define CURRENT_POSITIONS_REQUEST                   305
#define POSITION_REPORT                             306
#define CURRENT_POSITIONS_REQUEST_REJECT            307

// Account list
#define ACCOUNTS_REQUEST                            400
#define ACCOUNT_LIST_RESPONSE                       401

// Symbol discovery and security definitions
#define EXCHANGE_LIST_REQUEST                       500
#define EXCHANGE_LIST_RESPONSE                      501
#define SYMBOLS_FOR_EXCHANGE_REQUEST                502
#define UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST     503
#define SYMBOLS_FOR_UNDERLYING_REQUEST              504
#define SECURITY_DEFINITION_FOR_SYMBOL_REQUEST      506
#define SECURITY_DEFINITION_RESPONSE                507

// Account balance
#define ACCOUNT_BALANCE_UPDATE                      600

// Logging
#define USER_MESSAGE                                700
#define GENERAL_LOG_MESSAGE                         701

// Historical price data
#define HISTORICAL_PRICE_DATA_REQUEST               800
#define HISTORICAL_PRICE_DATA_HEADER_RESPONSE       801
#define HISTORICAL_PRICE_DATA_REJECT                802
#define HISTORICAL_PRICE_DATA_RECORD_RESPONSE       803
#define HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE  804


/*==========================================================================*/
//Standard UNIX date and time value
typedef int64_t t_DateTime;

// This is a 4 byte DateTime value used in messages where compactness is an important consideration.
typedef uint32_t t_DateTime4Byte;

/*==========================================================================*/
enum LogonStatusEnum {
    LOGON_SUCCESS = 1,
    LOGON_ERROR = 2,
    LOGON_ERROR_NO_RECONNECT = 3,
    LOGON_RECONNECT_NEW_ADDRESS = 4
};

/*==========================================================================*/
enum MessageSupportedEnum {
    MESSAGE_UNSUPPORTED = 0,
    MESSAGE_SUPPORTED = 1
};

/*==========================================================================*/
enum TradeModeEnum {
    TRADE_MODE_DEMO = 1,
    TRADE_MODE_SIMULATED = 2,
    TRADE_MODE_LIVE = 3
};

/*==========================================================================*/
enum RequestActionEnum {
    SUBSCRIBE = 1,
    UNSUBSCRIBE = 2,
    SNAPSHOT = 3
};

/*==========================================================================*/
enum OrderStatusEnum {
    ORDER_STATUS_UNSPECIFIED = 0,
    ORDER_STATUS_ORDERSENT = 1,
    ORDER_STATUS_PENDINGOPEN = 2,
    ORDER_STATUS_PENDINGCHILD = 3,
    ORDER_STATUS_OPEN = 4,
    ORDER_STATUS_PENDING_CANCEL_REPLACE = 5,
    ORDER_STATUS_PENDING_CANCEL = 6,
    ORDER_STATUS_FILLED = 7,
    ORDER_STATUS_CANCELED = 8,
    ORDER_STATUS_REJECTED = 9
};

/*==========================================================================*/
enum ExecutionTypeEnum {
    ET_UNSET = 0,
    ET_OPEN_ORDERS_REQUEST = 1,
    ET_NEW_ORDER_ACCEPTED = 2,
    ET_ORDER_UPDATE = 3,
    ET_FILLED = 4,
    ET_PARTIAL_FILL = 5,
    ET_CANCELED = 6,
    ET_CANCEL_REPLACE_COMPLETE = 7,
    ET_NEW_ORDER_REJECT = 8,
    ET_ORDER_CANCEL_REJECT = 9,
    ET_ORDER_CANCEL_REPLACE_REJECT = 10
};

/*==========================================================================*/
enum BidOrAskEnum {
    BID_ASK_UNSET = 0,
    AT_BID = 1,
    AT_ASK = 2
};

/*==========================================================================*/
enum MarketDepthIncrementalUpdateTypeEnum {
    DEPTH_UNSET = 0,
    DEPTH_INSERT_UPDATE = 1, // Insert or update depth at the given price level
    DEPTH_DELETE = 2 // Delete depth at the given price level
};

/*==========================================================================*/
enum OrderTypeEnum {
    ORDER_TYPE_UNSET = 0,
    ORDER_TYPE_MARKET = 1,
    ORDER_TYPE_LIMIT = 2,
    ORDER_TYPE_STOP = 3,
    ORDER_TYPE_STOP_LIMIT = 4,
    ORDER_TYPE_MARKET_IF_TOUCHED = 5
};

/*==========================================================================*/
enum TimeInForceEnum {
    TIF_UNSET = 0,
    TIF_DAY = 1,
    TIF_GOOD_TILL_CANCELED = 2,
    TIF_GOOD_TILL_DATE_TIME = 3,
    TIF_IMMEDIATE_OR_CANCEL = 4,
    TIF_ALL_OR_NONE = 5,
    TIF_FILL_OR_KILL = 6
};

/*==========================================================================*/
enum BuySellEnum {
    BUY_SELL_UNSET = 0,
    BUY = 1,
    SELL = 2
};

/*==========================================================================*/
enum OpenCloseTradeEnum {
    TRADE_UNSET = 0,
    TRADE_OPEN = 1,
    TRADE_CLOSE = 2
};

/*==========================================================================*/

enum MarketDataFeedStatusEnum {
    MARKET_DATA_FEED_LOST = 1,
    MARKET_DATA_FEED_RESTORED = 2
};

/*==========================================================================*/
enum DisplayFormatEnum {
    DISPLAY_FORMAT_UNSET =  -1,
    //The following formats indicate the number of decimal places to be displayed
    DISPLAY_FORMAT_DECIMAL_0 = 0,
    DISPLAY_FORMAT_DECIMAL_1 = 1,
    DISPLAY_FORMAT_DECIMAL_2 = 2,
    DISPLAY_FORMAT_DECIMAL_3 = 3,
    DISPLAY_FORMAT_DECIMAL_4 = 4,
    DISPLAY_FORMAT_DECIMAL_5 = 5,
    DISPLAY_FORMAT_DECIMAL_6 = 6,
    DISPLAY_FORMAT_DECIMAL_7 = 7,
    DISPLAY_FORMAT_DECIMAL_8 = 8,
    DISPLAY_FORMAT_DECIMAL_9 = 9,
    //The following formats are fractional formats
    DISPLAY_FORMAT_DENOMINATOR_256 = 356,
    DISPLAY_FORMAT_DENOMINATOR_128 = 228,
    DISPLAY_FORMAT_DENOMINATOR_64 = 164,
    DISPLAY_FORMAT_DENOMINATOR_32_QUARTERS = 136,
    DISPLAY_FORMAT_DENOMINATOR_32_HALVES = 134,
    DISPLAY_FORMAT_DENOMINATOR_32 = 132,
    DISPLAY_FORMAT_DENOMINATOR_16 = 116,
    DISPLAY_FORMAT_DENOMINATOR_8 = 108,
    DISPLAY_FORMAT_DENOMINATOR_4 = 104,
    DISPLAY_FORMAT_DENOMINATOR_2 = 102
};

/*==========================================================================*/
enum SecurityTypeEnum {
    ST_UNSET = 0,
    ST_FUTURE = 1,
    ST_STOCK = 2,
    ST_FOREX = 3, // Bitcoins also go into this category
    ST_INDEX = 4,
    ST_FUTURES_STRATEGY = 5,
    ST_STOCK_OPTION = 6,
    ST_FUTURES_OPTION = 7,
    ST_INDEX_OPTION = 8,
    ST_BOND = 9,
    ST_MUTUAL_FUND = 10
};

/*==========================================================================*/
enum HistoricalDataIntervalEnum {
    INTERVAL_TICK = 0,
    INTERVAL_1_SECOND = 1,
    INTERVAL_2_SECONDS = 2,
    INTERVAL_4_SECONDS = 4,
    INTERVAL_5_SECONDS = 5,
    INTERVAL_10_SECONDS = 10,
    INTERVAL_30_SECONDS = 30,
    INTERVAL_1_MINUTE = 60,
    INTERVAL_1_DAY = 86400,
    INTERVAL_1_WEEK = 604800
};

/*==========================================================================*/
#define MESSAGE_HEAD uint16_t Size; uint16_t Type

struct s_MessageHeader {
    MESSAGE_HEAD;
};

#define GET_MESSAGE_TYPE(x) (struct s_MessageHeader*)(x)->Type
#define GET_MESSAGE_SIZE(x) (struct s_MessageHeader*)(x)->Size

/*==========================================================================*/
struct s_LogonRequest {
    MESSAGE_HEAD;
    int32_t ProtocolVersion;
    char Username[32];
    char Password[32];
    char GeneralTextData[64];
    int32_t Integer_1;
    int32_t Integer_2;
    int32_t  HeartbeatIntervalInSeconds;
    TradeModeEnum TradeMode;
    char TradeAccount[TRADE_ACCOUNT_LENGTH];
    char HardwareIdentifier[64];
    char ClientName[32];
};

void LogonRequest_init(struct s_LogonRequest *msg)
{
    memset(msg, 0, sizeof(struct s_LogonRequest));
    msg->Type = LOGON_REQUEST;
    msg->Size = sizeof(struct s_LogonRequest);
    msg->ProtocolVersion = CURRENT_VERSION;
}

/*==========================================================================*/
struct s_LogonResponse {
    MESSAGE_HEAD;
    int32_t ProtocolVersion;
    LogonStatusEnum Result;
    char ResultText[TEXT_DESCRIPTION_LENGTH];
    char ReconnectAddress [64];
    int32_t Integer_1;
    char ServerVersion[12];
    char ServerName[24];
    char ServiceProviderName[24];
    uint8_t MarketDepthUpdatesBestBidAndAsk;
    uint8_t TradingIsSupported;
    uint8_t OCOOrdersSupported;
    uint8_t OrderCancelReplaceSupported;
    char SymbolExchangeDelimiter[4];
    uint8_t SecurityDefinitionsSupported;
    uint8_t HistoricalPriceDataSupported;
    uint8_t ResubscribeWhenMarketDataFeedRestored;
    uint8_t MarketDepthIsSupported;
    uint8_t OneHistoricalPriceDataRequestPerConnection;
};

void LogonResponse_init(struct s_LogonResponse *msg)
{
    memset(msg, 0, sizeof(struct s_LogonResponse));
    msg->Type = LOGON_RESPONSE;
    msg->Size = sizeof(struct s_LogonResponse);
    msg->ProtocolVersion = CURRENT_VERSION;
    msg->OrderCancelReplaceSupported = 1;
    msg->MarketDepthIsSupported = 1;
}

/*==========================================================================*/
struct s_LogoffRequest {
    MESSAGE_HEAD;
    char Reason[TEXT_DESCRIPTION_LENGTH];
};

void LogoffRequest_init(struct s_LogoffRequest *msg)
{
    memset(msg, 0, sizeof(struct s_LogoffRequest));
    msg->Type = LOGOFF_REQUEST;
    msg->Size = sizeof(struct s_LogoffRequest);
}

/*==========================================================================*/
struct s_Heartbeat {
    MESSAGE_HEAD;
    uint32_t DroppedMessages;
    t_DateTime CurrentDateTime;
};

void Heartbeat_init(struct s_Heartbeat *msg)
{
    memset(msg, 0, sizeof(struct s_Heartbeat));
    msg->Type = HEARTBEAT;
    msg->Size = sizeof(struct s_Heartbeat);
}

/*==========================================================================*/
struct s_DisconnectFromServer {
    MESSAGE_HEAD;
    char DisconnectReason[TEXT_DESCRIPTION_LENGTH];
};

void DisconnectFromServer_init(struct s_DisconnectFromServer *msg)
{
    memset(msg, 0, sizeof(struct s_DisconnectFromServer));
    msg->Type = DISCONNECT_FROM_SERVER_NO_RECONNECT;
    msg->Size = sizeof(struct s_DisconnectFromServer);
}

/*==========================================================================*/
struct s_MarketDataFeedStatus {
    MESSAGE_HEAD;
    MarketDataFeedStatusEnum Status;
};

void MarketDataFeedStatus_init(struct s_MarketDataFeedStatus *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDataFeedStatus));
    msg->Type = MARKET_DATA_FEED_STATUS;
    msg->Size = sizeof(struct s_MarketDataFeedStatus);
}

/*==========================================================================*/
struct s_MarketDataFeedSymbolStatus {
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    MarketDataFeedStatusEnum Status;
};

void MarketDataFeedSymbolStatus_init(struct s_MarketDataFeedSymbolStatus *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDataFeedSymbolStatus));
    msg->Type = MARKET_DATA_FEED_SYMBOL_STATUS;
    msg->Size = sizeof(struct s_MarketDataFeedSymbolStatus);
}

/*==========================================================================*/
struct s_MarketDataRequest {
    MESSAGE_HEAD;
    RequestActionEnum RequestActionValue;
    uint16_t MarketDataSymbolID;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
};

void MarketDataRequest_init(struct s_MarketDataRequest *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDataRequest));
    msg->Type = MARKET_DATA_REQUEST;
    msg->Size = sizeof(struct s_MarketDataRequest);
    msg->RequestActionValue = SUBSCRIBE;
}

/*==========================================================================*/
struct s_MarketDepthRequest {
    MESSAGE_HEAD;
    RequestActionEnum RequestActionValue;
    uint16_t MarketDataSymbolID;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
    int32_t NumberOfLevels;
};

void MarketDepthRequest_init(struct s_MarketDepthRequest *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthRequest));
    msg->Type = MARKET_DEPTH_REQUEST;
    msg->Size = sizeof(struct s_MarketDepthRequest);

    msg->RequestActionValue = SUBSCRIBE;
    msg->NumberOfLevels = 10;
}

/*==========================================================================*/
struct s_MarketDataReject {
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    char RejectText[TEXT_DESCRIPTION_LENGTH];
};

void MarketDataReject_init(struct s_MarketDataReject *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDataReject));
    msg->Type = MARKET_DATA_REJECT;
    msg->Size = sizeof(struct s_MarketDataReject);
}

/*==========================================================================*/
struct s_MarketDataSnapshot {
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    double SettlementPrice;
    double DailyOpen;
    double DailyHigh;
    double DailyLow;
    double DailyVolume;
    uint32_t DailyNumberOfTrades;
    union {
        uint32_t SharesOutstanding;
        uint32_t OpenInterest;
        uint32_t UnitsOutstanding;
    };

    double Bid;
    double Ask;
    double AskSize;
    double BidSize;
    double LastTradePrice;
    double LastTradeSize;
    double LastTradeDateTimeUnix;
};

void MarketDataSnapshot_init(struct s_MarketDataSnapshot *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDataSnapshot));
    msg->Type = MARKET_DATA_SNAPSHOT;
    msg->Size = sizeof(struct s_MarketDataSnapshot);
}

/*==========================================================================*/
struct s_FundamentalDataResponse {
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    char SymbolDescription[SYMBOL_DESCRIPTION_LENGTH];
    float TickSize;
    float TickCurrencyValue;
    DisplayFormatEnum DisplayFormat;
    float BuyRolloverInterest;
    float SellRolloverInterest;
    float OrderPriceMultiplier;
};

void FundamentalDataResponse_init(struct s_FundamentalDataResponse *msg)
{
    memset(msg, 0, sizeof(struct s_FundamentalDataResponse));
    msg->Type = FUNDAMENTAL_DATA_RESPONSE;
    msg->Size = sizeof(struct s_FundamentalDataResponse);
    msg->DisplayFormat = DISPLAY_FORMAT_UNSET;
}

/*==========================================================================*/
#define NUM_DEPTH_LEVELS_20 20

struct s_MarketDepthFullUpdate20 {
    MESSAGE_HEAD;

    uint16_t MarketDataSymbolID;

    struct {
        double Price;
        float Volume;
    } BidDepth[NUM_DEPTH_LEVELS_20], AskDepth[NUM_DEPTH_LEVELS_20];
};

void MarketDepthFullUpdate20_init(struct s_MarketDepthFullUpdate20 *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthFullUpdate20));
    msg->Type = MARKET_DEPTH_FULL_UPDATE_20;
    msg->Size = sizeof(struct s_MarketDepthFullUpdate20);
}

/*==========================================================================*/
#define NUM_DEPTH_LEVELS_10 10

struct s_MarketDepthFullUpdate10 {
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;

    struct {
        double Price;
        float Volume;
    } BidDepth[NUM_DEPTH_LEVELS_10], AskDepth[NUM_DEPTH_LEVELS_10];
};

void MarketDepthFullUpdate10_init(struct s_MarketDepthFullUpdate10 *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthFullUpdate10));
    msg->Type = MARKET_DEPTH_FULL_UPDATE_10;
    msg->Size = sizeof(struct s_MarketDepthFullUpdate10);
}

/*==========================================================================*/
struct s_MarketDepthSnapshotLevel {

    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    BidOrAskEnum Side;
    double Price;
    double Volume;
    uint16_t  Level;

    uint8_t FirstMessageInBatch;
    uint8_t LastMessageInBatch;
};

void MarketDepthSnapshotLevel_init(struct s_MarketDepthSnapshotLevel *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthSnapshotLevel));
    msg->Type = MARKET_DEPTH_SNAPSHOT_LEVEL;
    msg->Size = sizeof(struct s_MarketDepthSnapshotLevel);

}

/*==========================================================================*/
struct s_MarketDepthIncrementalUpdate {
    MESSAGE_HEAD;

    uint16_t MarketDataSymbolID;
    BidOrAskEnum Side;
    double Price;
    double Volume;

    MarketDepthIncrementalUpdateTypeEnum UpdateType;
};

void MarketDepthIncrementalUpdate_init(struct s_MarketDepthIncrementalUpdate *msg)
{

    memset(msg, 0, sizeof(struct s_MarketDepthIncrementalUpdate));
    msg->Type = MARKET_DEPTH_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_MarketDepthIncrementalUpdate);

}

/*==========================================================================*/
struct s_MarketDepthIncrementalUpdateCompact {
    MESSAGE_HEAD;

    uint16_t MarketDataSymbolID;
    BidOrAskEnum Side;
    float Price;
    float Volume;

    MarketDepthIncrementalUpdateTypeEnum UpdateType;
};

void MarketDepthIncrementalUpdateCompact_init(struct s_MarketDepthIncrementalUpdateCompact *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthIncrementalUpdateCompact));
    msg->Type = MARKET_DEPTH_INCREMENTAL_UPDATE_COMPACT;
    msg->Size = sizeof(struct s_MarketDepthIncrementalUpdateCompact);
}

/*==========================================================================*/
struct s_SettlementIncrementalUpdate {
    MESSAGE_HEAD;

    uint16_t MarketDataSymbolID;
    double SettlementPrice;
};

void SettlementIncrementalUpdate_init(struct s_SettlementIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_SettlementIncrementalUpdate));
    msg->Type = SETTLEMENT_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_SettlementIncrementalUpdate);
}

/*==========================================================================*/
struct s_DailyOpenIncrementalUpdate {
    MESSAGE_HEAD;

    uint16_t MarketDataSymbolID;
    double DailyOpen;
};

void DailyOpenIncrementalUpdate_init(struct s_DailyOpenIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_DailyOpenIncrementalUpdate));
    msg->Type = DAILY_OPEN_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_DailyOpenIncrementalUpdate);
}

/*==========================================================================*/
struct s_MarketDepthReject {
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    char RejectText[TEXT_DESCRIPTION_LENGTH];
};

void MarketDepthReject_init(struct s_MarketDepthReject *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthReject));
    msg->Type = MARKET_DEPTH_REJECT;
    msg->Size = sizeof(struct s_MarketDepthReject);
}

/*==========================================================================*/

struct s_TradeIncrementalUpdate {
    MESSAGE_HEAD;

    uint16_t MarketDataSymbolID;

    BidOrAskEnum TradeAtBidOrAsk;

    double Price;
    double TradeVolume;
    double TradeDateTimeUnix;
};

void TradeIncrementalUpdate_init(struct s_TradeIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_TradeIncrementalUpdate));
    msg->Type = TRADE_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_TradeIncrementalUpdate);
}

/*==========================================================================*/

struct s_QuoteIncrementalUpdate {
    MESSAGE_HEAD;

    uint16_t MarketDataSymbolID;

    double BidPrice;
    float BidSize;
    double AskPrice;
    float AskSize;
    double QuoteDateTimeUnix;
};

void QuoteIncrementalUpdate_init(struct s_QuoteIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_QuoteIncrementalUpdate));
    msg->Type = QUOTE_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_QuoteIncrementalUpdate);
    msg->BidPrice = DBL_MAX;
    msg->AskPrice = DBL_MAX;
}

/*==========================================================================*/

struct s_QuoteIncrementalUpdateCompact {
    MESSAGE_HEAD;

    float BidPrice;
    float BidSize;
    float AskPrice;
    float AskSize;

    t_DateTime4Byte QuoteDateTimeUnix;

    uint16_t MarketDataSymbolID;
};

void QuoteIncrementalUpdateCompact_init(struct s_QuoteIncrementalUpdateCompact *msg)
{
    memset(msg, 0, sizeof(struct s_QuoteIncrementalUpdateCompact));
    msg->Type = QUOTE_INCREMENTAL_UPDATE_COMPACT;
    msg->Size = sizeof(struct s_QuoteIncrementalUpdateCompact);
    msg->BidPrice = FLT_MAX;
    msg->AskPrice = FLT_MAX;
}

/*==========================================================================*/

struct s_TradeIncrementalUpdateCompact {
    MESSAGE_HEAD;

    float Price;
    float TradeVolume;
    t_DateTime4Byte TradeDateTimeUnix;
    uint16_t MarketDataSymbolID;
    BidOrAskEnum TradeAtBidOrAsk;
};

void TradeIncrementalUpdateCompact_init(struct s_TradeIncrementalUpdateCompact *msg)
{
    memset(msg, 0, sizeof(struct s_TradeIncrementalUpdateCompact));
    msg->Type = TRADE_INCREMENTAL_UPDATE_COMPACT;
    msg->Size = sizeof(struct s_TradeIncrementalUpdateCompact);
}

/*==========================================================================*/
struct s_DailyVolumeIncrementalUpdate {
    MESSAGE_HEAD;

    uint16_t MarketDataSymbolID;
    double DailyVolume;
};

void DailyVolumeIncrementalUpdate_init(struct s_DailyVolumeIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_DailyVolumeIncrementalUpdate));
    msg->Type = DAILY_VOLUME_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_DailyVolumeIncrementalUpdate);
}

/*==========================================================================*/
struct s_OpenInterestIncrementalUpdate {
    MESSAGE_HEAD;

    uint16_t MarketDataSymbolID;
    uint32_t OpenInterest;
};

void OpenInterestIncrementalUpdate_init(struct s_OpenInterestIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_OpenInterestIncrementalUpdate));
    msg->Type = OPEN_INTEREST_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_OpenInterestIncrementalUpdate);
}


/*==========================================================================*/
struct s_DailyHighIncrementalUpdate {
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    double DailyHigh;
};

void DailyHighIncrementalUpdate_init(struct s_DailyHighIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_DailyHighIncrementalUpdate));
    msg->Type = DAILY_HIGH_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_DailyHighIncrementalUpdate);
}

/*==========================================================================*/
struct s_DailyLowIncrementalUpdate {
    MESSAGE_HEAD;

    uint16_t MarketDataSymbolID;
    double DailyLow;
};

void DailyLowIncrementalUpdate_init(struct s_DailyLowIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_DailyLowIncrementalUpdate));
    msg->Type = DAILY_LOW_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_DailyLowIncrementalUpdate);
}

/*==========================================================================*/

struct s_SubmitNewSingleOrder {

    MESSAGE_HEAD;

    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];

    char ClientOrderID[ORDER_ID_LENGTH];

    OrderTypeEnum OrderType;
    BuySellEnum BuySell;

    double Price1;

    double Price2;

    TimeInForceEnum TimeInForce;
    t_DateTime GoodTillDateTimeUnix;
    double OrderQuantity;
    char TradeAccount[TRADE_ACCOUNT_LENGTH];

    char IsAutomatedOrder;

    char IsParentOrder;

    int32_t Price1AsInteger;
    int32_t Price2AsInteger;
    float Divisor;
};

void SubmitNewSingleOrder_init(struct s_SubmitNewSingleOrder *msg)
{
    memset(msg, 0, sizeof(struct s_SubmitNewSingleOrder));
    msg->Type = SUBMIT_NEW_SINGLE_ORDER;
    msg->Size = sizeof(struct s_SubmitNewSingleOrder);
}

/*==========================================================================*/

struct s_CancelReplaceOrder {

    MESSAGE_HEAD;

    char ServerOrderID[ORDER_ID_LENGTH];
    char ClientOrderID[ORDER_ID_LENGTH];

    double Price1;
    double Price2;

    double OrderQuantity;

    char TradeAccount [TRADE_ACCOUNT_LENGTH];//Not required by DTC

    int32_t Price1AsInteger;
    int32_t Price2AsInteger;
    float Divisor;
};

void CancelReplaceOrder_init(struct s_CancelReplaceOrder *msg)
{
    memset(msg, 0, sizeof(struct s_CancelReplaceOrder));
    msg->Type = CANCEL_REPLACE_ORDER;
    msg->Size = sizeof(struct s_CancelReplaceOrder);
}

/*==========================================================================*/

struct s_CancelOrder {

    MESSAGE_HEAD;

    char ServerOrderID[ORDER_ID_LENGTH];
    char ClientOrderID[ORDER_ID_LENGTH];
    char TradeAccount [TRADE_ACCOUNT_LENGTH];

    char Symbol[SYMBOL_LENGTH];//Not required by DTC
    char Exchange[EXCHANGE_LENGTH];//Not required by DTC
};

void CancelOrder_init(struct s_CancelOrder *msg)
{
    memset(msg, 0, sizeof(struct s_CancelOrder));
    msg->Type = CANCEL_ORDER;
    msg->Size = sizeof(struct s_CancelOrder);
}

/*==========================================================================*/

struct s_SubmitNewOCOOrder {
    MESSAGE_HEAD;

    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];

    char ClientOrderID_1[ORDER_ID_LENGTH];
    OrderTypeEnum OrderType_1;
    BuySellEnum BuySell_1;
    double Price1_1;
    double Price2_1;
    double OrderQuantity_1;

    char ClientOrderID_2[ORDER_ID_LENGTH];
    OrderTypeEnum OrderType_2;
    BuySellEnum BuySell_2;
    double Price1_2;
    double Price2_2;
    double OrderQuantity_2;

    TimeInForceEnum TimeInForce;
    t_DateTime GoodTillDateTimeUnix;

    char TradeAccount[TRADE_ACCOUNT_LENGTH];

    char IsAutomatedOrder;

    char ParentTriggerClientOrderID[ORDER_ID_LENGTH];
};

void SubmitNewOCOOrder_init(struct s_SubmitNewOCOOrder *msg)
{
    memset(msg, 0, sizeof(struct s_SubmitNewOCOOrder));
    msg->Type = SUBMIT_NEW_OCO_ORDER;
    msg->Size = sizeof(struct s_SubmitNewOCOOrder);
}

/*==========================================================================*/

struct s_OpenOrdersRequest {
    MESSAGE_HEAD;

    int32_t RequestID;

    int32_t RequestAllOpenOrders;

    char ServerOrderID[ORDER_ID_LENGTH];
};

void OpenOrdersRequest_init(struct s_OpenOrdersRequest *msg)
{
    memset(msg, 0, sizeof(struct s_OpenOrdersRequest));
    msg->Type = OPEN_ORDERS_REQUEST;
    msg->Size = sizeof(struct s_OpenOrdersRequest);
    msg->RequestAllOpenOrders = 1;
}

/*==========================================================================*/

struct s_HistoricalOrderFillsRequest {
    MESSAGE_HEAD;

    int32_t RequestID;

    char ServerOrderID[ORDER_ID_LENGTH];

    int32_t NumberOfDays;

    char TradeAccount[TRADE_ACCOUNT_LENGTH];
};

void HistoricalOrderFillsRequest_init(struct s_HistoricalOrderFillsRequest *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalOrderFillsRequest));
    msg->Type = HISTORICAL_ORDER_FILLS_REQUEST;
    msg->Size = sizeof(struct s_HistoricalOrderFillsRequest);
}

/*==========================================================================*/

struct s_CurrentPositionsRequest {
    MESSAGE_HEAD;

    int32_t RequestID;
    char  TradeAccount[TRADE_ACCOUNT_LENGTH];
};

void CurrentPositionsRequest_init(struct s_CurrentPositionsRequest *msg)
{
    memset(msg, 0, sizeof(struct s_CurrentPositionsRequest));
    msg->Type = CURRENT_POSITIONS_REQUEST;
    msg->Size = sizeof(struct s_CurrentPositionsRequest);
}

/*==========================================================================*/
struct s_CurrentPositionsRequestReject {
    MESSAGE_HEAD;

    int32_t RequestID;
    char RejectText[TEXT_DESCRIPTION_LENGTH];
};

void CurrentPositionsRequestReject_init(struct s_CurrentPositionsRequestReject *msg)
{
    memset(msg, 0, sizeof(struct s_CurrentPositionsRequestReject));
    msg->Type = CURRENT_POSITIONS_REQUEST_REJECT;
    msg->Size = sizeof(struct s_CurrentPositionsRequestReject);
}

/*==========================================================================*/

struct s_OrderUpdateReport {
    MESSAGE_HEAD;

    int32_t RequestID;

    int32_t TotalNumberMessages;
    int32_t MessageNumber;

    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];

    char PreviousServerOrderID[ORDER_ID_LENGTH];

    char ServerOrderID[ORDER_ID_LENGTH];

    char ClientOrderID[ORDER_ID_LENGTH];

    char ExchangeOrderID[ORDER_ID_LENGTH];

    OrderStatusEnum OrderStatus;

    ExecutionTypeEnum ExecutionType;

    OrderTypeEnum OrderType;

    BuySellEnum BuySell;

    double Price1;

    double Price2;

    TimeInForceEnum TimeInForce;
    t_DateTime GoodTillDateTimeUnix;
    double OrderQuantity;
    double FilledQuantity;
    double RemainingQuantity;
    double AverageFillPrice;

    double LastFillPrice;
    t_DateTime LastFillDateTimeUnix;
    double LastFillQuantity;
    char UniqueFillExecutionID[64];

    char TradeAccount[TRADE_ACCOUNT_LENGTH];
    char InfoText[TEXT_DESCRIPTION_LENGTH];

    char NoneOrders;
};

void OrderUpdateReport_init(struct s_OrderUpdateReport *msg)
{
    memset(msg, 0, sizeof(struct s_OrderUpdateReport));
    msg->Type = ORDER_UPDATE_REPORT;
    msg->Size = sizeof(struct s_OrderUpdateReport);

    //The following initializations indicate to the Client that these variables are in an unset state and their values should not be used
    msg->Price1 = DBL_MAX;
    msg->Price2 = DBL_MAX;

    msg->OrderQuantity = DBL_MAX;
    msg->FilledQuantity = DBL_MAX;
    msg->RemainingQuantity = DBL_MAX;
    msg->AverageFillPrice = DBL_MAX;

    msg->LastFillPrice = DBL_MAX;
    msg->LastFillQuantity = DBL_MAX;
}

/*==========================================================================*/
struct s_OpenOrdersRequestReject {
    MESSAGE_HEAD;

    int32_t RequestID;
    char RejectText[TEXT_DESCRIPTION_LENGTH];
};

void OpenOrdersRequestReject_init(struct s_OpenOrdersRequestReject *msg)
{
    memset(msg, 0, sizeof(struct s_OpenOrdersRequestReject));
    msg->Type = OPEN_ORDERS_REQUEST_REJECT;
    msg->Size = sizeof(struct s_OpenOrdersRequestReject);
}

/*==========================================================================*/

struct s_HistoricalOrderFillReport {
    MESSAGE_HEAD;

    int32_t RequestID;

    int32_t TotalNumberMessages;

    int32_t MessageNumber;

    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
    char ServerOrderID[ORDER_ID_LENGTH];
    BuySellEnum BuySell;
    double FillPrice;
    t_DateTime FillDateTimeUnix;
    double FillQuantity;
    char UniqueFillExecutionID[64];
    char TradeAccount[TRADE_ACCOUNT_LENGTH];

    OpenCloseTradeEnum OpenClose;

    char NoneOrderFills;
};

void HistoricalOrderFillReport_init(struct s_HistoricalOrderFillReport *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalOrderFillReport));
    msg->Type = HISTORICAL_ORDER_FILL_REPORT;
    msg->Size = sizeof(struct s_HistoricalOrderFillReport);
}

/*==========================================================================*/

struct s_PositionReport {
    MESSAGE_HEAD;
    int32_t RequestID;

    int32_t TotalNumberMessages;

    int32_t MessageNumber;

    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];

    double PositionQuantity;
    double AveragePrice;

    char PositionIdentifier [ORDER_ID_LENGTH];

    char TradeAccount[TRADE_ACCOUNT_LENGTH];
    char NonePositions;

    char Unsolicited;
};

void PositionReport_init(struct s_PositionReport *msg)
{
    memset(msg, 0, sizeof(struct s_PositionReport));
    msg->Type = POSITION_REPORT;
    msg->Size = sizeof(struct s_PositionReport);
}

/*==========================================================================*/

struct s_AccountsRequest {
    MESSAGE_HEAD;
};

void AccountsRequest_init(struct s_AccountsRequest *msg)
{
    memset(msg, 0, sizeof(struct s_AccountsRequest));
    msg->Type = ACCOUNTS_REQUEST;
    msg->Size = sizeof(struct s_AccountsRequest);
}

/*==========================================================================*/
struct s_AccountListResponse {
    MESSAGE_HEAD;

    int32_t TotalNumberMessages;

    int32_t MessageNumber;

    char TradeAccount[TRADE_ACCOUNT_LENGTH];
};

void AccountListResponse_init(struct s_AccountListResponse *msg)
{
    memset(msg, 0, sizeof(struct s_AccountListResponse));
    msg->Type = ACCOUNT_LIST_RESPONSE;
    msg->Size = sizeof(struct s_AccountListResponse);
}

/*==========================================================================*/
struct s_ExchangeListRequest {
    MESSAGE_HEAD;

    int32_t RequestID;
};

void ExchangeListRequest_init(struct s_ExchangeListRequest *msg)
{
    memset(msg, 0, sizeof(struct s_ExchangeListRequest));
    msg->Type = EXCHANGE_LIST_REQUEST;
    msg->Size = sizeof(struct s_ExchangeListRequest);
}

/*==========================================================================*/
struct s_ExchangeListResponse {
    MESSAGE_HEAD;

    int32_t RequestID;
    char Exchange[EXCHANGE_LENGTH];
    char FinalMessage;
    char ExchangeDescription[EXCHANGE_DESCRIPTION_LENGTH];
};

void ExchangeListResponse_init(struct s_ExchangeListResponse *msg)
{
    memset(msg, 0, sizeof(struct s_ExchangeListResponse));
    msg->Type = EXCHANGE_LIST_RESPONSE;
    msg->Size = sizeof(struct s_ExchangeListResponse);
}

/*==========================================================================*/
struct s_SymbolsForExchangeRequest {
    MESSAGE_HEAD;

    int32_t RequestID;
    char Exchange[EXCHANGE_LENGTH];

    SecurityTypeEnum SecurityType;
};

void SymbolsForExchangeRequest_init(struct s_SymbolsForExchangeRequest *msg)
{
    memset(msg, 0, sizeof(struct s_SymbolsForExchangeRequest));
    msg->Type = SYMBOLS_FOR_EXCHANGE_REQUEST;
    msg->Size = sizeof(struct s_SymbolsForExchangeRequest);
}

/*==========================================================================*/
struct s_UnderlyingSymbolsForExchangeRequest {
    MESSAGE_HEAD;

    int32_t RequestID;

    char Exchange[EXCHANGE_LENGTH];

    SecurityTypeEnum SecurityType;
};

void UnderlyingSymbolsForExchangeRequest_init(struct s_UnderlyingSymbolsForExchangeRequest *msg)
{
    memset(msg, 0, sizeof(struct s_UnderlyingSymbolsForExchangeRequest));
    msg->Type = UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST;
    msg->Size = sizeof(struct s_UnderlyingSymbolsForExchangeRequest);
}

/*==========================================================================*/
struct s_SymbolsForUnderlyingRequest {
    MESSAGE_HEAD;

    int32_t RequestID;

    char UnderlyingSymbol[UNDERLYING_SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];

    SecurityTypeEnum SecurityType;
};

void SymbolsForUnderlyingRequest_init(struct s_SymbolsForUnderlyingRequest *msg)
{
    memset(msg, 0, sizeof(struct s_SymbolsForUnderlyingRequest));
    msg->Type = SYMBOLS_FOR_UNDERLYING_REQUEST;
    msg->Size = sizeof(struct s_SymbolsForUnderlyingRequest);
}

/*==========================================================================*/
struct s_SecurityDefinitionForSymbolRequest {
    MESSAGE_HEAD;

    int32_t RequestID;

    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];

    SecurityTypeEnum SecurityType;
};

void SecurityDefinitionForSymbolRequest_init(struct s_SecurityDefinitionForSymbolRequest *msg)
{
    memset(msg, 0, sizeof(struct s_SecurityDefinitionForSymbolRequest));
    msg->Type = SECURITY_DEFINITION_FOR_SYMBOL_REQUEST;
    msg->Size = sizeof(struct s_SecurityDefinitionForSymbolRequest);
}

/*==========================================================================*/
struct s_SecurityDefinitionResponse {
    MESSAGE_HEAD;

    int32_t RequestID;

    char Symbol[SYMBOL_LENGTH];

    char Exchange[EXCHANGE_LENGTH];

    SecurityTypeEnum SecurityType;

    char SymbolDescription[SYMBOL_DESCRIPTION_LENGTH];
    float TickSize;
    DisplayFormatEnum PriceDisplayFormat;
    float TickCurrencyValue;

    char FinalMessage;
};

void SecurityDefinitionResponse_init(struct s_SecurityDefinitionResponse *msg)
{
    memset(msg, 0, sizeof(struct s_SecurityDefinitionResponse));
    msg->Type = SECURITY_DEFINITION_RESPONSE;
    msg->Size = sizeof(struct s_SecurityDefinitionResponse);
}

/*==========================================================================*/
struct s_AccountBalanceUpdate {
    MESSAGE_HEAD;

    double CurrentCashBalance;

    double CurrentBalanceAvailableForNewPositions;

    char AccountCurrency[8];

    char TradeAccount[TRADE_ACCOUNT_LENGTH];
};

void AccountBalanceUpdate_init(struct s_AccountBalanceUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_AccountBalanceUpdate));
    msg->Type = ACCOUNT_BALANCE_UPDATE;
    msg->Size = sizeof(struct s_AccountBalanceUpdate);
}

/*==========================================================================*/
struct s_UserMessage {
    MESSAGE_HEAD;

    char UserMessage[TEXT_MESSAGE_LENGTH];

    char PopupMessage;
};

void UserMessage_init(struct s_UserMessage *msg)
{
    memset(msg, 0, sizeof(struct s_UserMessage));
    msg->Type = USER_MESSAGE;
    msg->Size = sizeof(struct s_UserMessage);
    msg->PopupMessage = 1;
}

/*==========================================================================*/
struct s_GeneralLogMessage {
    MESSAGE_HEAD;

    char MessageText[128];
};

void GeneralLogMessage_init(struct s_GeneralLogMessage *msg)
{
    memset(msg, 0, sizeof(struct s_GeneralLogMessage));
    msg->Type = GENERAL_LOG_MESSAGE;
    msg->Size = sizeof(struct s_GeneralLogMessage);
}

/*==========================================================================*/
struct s_HistoricalPriceDataRequest {
    MESSAGE_HEAD;

    int32_t RequestIdentifier;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
    HistoricalDataIntervalEnum DataInterval;
    t_DateTime StartDateTime;
    t_DateTime EndDateTime;
    uint32_t MaximumDaysToReturn;
    char  UseZLibCompression;

    char DividendAdjustedStockData;
    char DelayedData;
};

void HistoricalPriceDataRequest_init(struct s_HistoricalPriceDataRequest *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalPriceDataRequest));
    msg->Type = HISTORICAL_PRICE_DATA_REQUEST;
    msg->Size = sizeof(struct s_HistoricalPriceDataRequest);
}

/*==========================================================================*/

struct s_HistoricalPriceDataHeaderResponse {
    MESSAGE_HEAD;
    int32_t RequestIdentifier;
    HistoricalDataIntervalEnum DataInterval;

    char RecordsUseZLibCompression;

    char NoRecordsToReturn;
};

void HistoricalPriceDataHeaderResponse_init(struct s_HistoricalPriceDataHeaderResponse *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalPriceDataHeaderResponse));
    msg->Type = HISTORICAL_PRICE_DATA_HEADER_RESPONSE;
    msg->Size = sizeof(struct s_HistoricalPriceDataHeaderResponse);
}

/*==========================================================================*/

struct s_HistoricalPriceDataReject {
    MESSAGE_HEAD;
    int32_t RequestIdentifier;

    char RejectText[TEXT_DESCRIPTION_LENGTH];
};

void HistoricalPriceDataReject_init(struct s_HistoricalPriceDataReject *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalPriceDataReject));
    msg->Type = HISTORICAL_PRICE_DATA_REJECT;
    msg->Size = sizeof(struct s_HistoricalPriceDataReject);
}

/*==========================================================================*/

struct s_HistoricalPriceDataRecordResponse {
    MESSAGE_HEAD;
    int32_t RequestIdentifier;

    t_DateTime StartingDateTime;
    double Open;
    double High;
    double Low;
    double Last;
    double Volume;
    union {
        uint32_t OpenInterest;
        uint32_t NumberTrades;
    };
    double BidVolume;
    double AskVolume;

    char FinalRecord;
};

void HistoricalPriceDataRecordResponse_init(struct s_HistoricalPriceDataRecordResponse *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalPriceDataRecordResponse));
    msg->Type = HISTORICAL_PRICE_DATA_RECORD_RESPONSE;
    msg->Size = sizeof(struct s_HistoricalPriceDataRecordResponse);
}

/*
void Clear()
{

    RequestIdentifier = 0;
    StartingDateTime = 0;
    Open = 0;
    High = 0;
    Low = 0;
    Last = 0;
    Volume = 0;
    OpenInterest = 0;
    BidVolume = 0;
    AskVolume = 0;
    FinalRecord = 0;
}
*/

/*==========================================================================*/

struct s_HistoricalPriceDataTickRecordResponse {
    MESSAGE_HEAD;
    int32_t RequestIdentifier;

    double TradeDateTimeWithMilliseconds;
    BidOrAskEnum BidOrAsk;

    double TradePrice;
    double TradeVolume;

    char FinalRecord;
};

void HistoricalPriceDataTickRecordResponse_init(struct s_HistoricalPriceDataTickRecordResponse *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalPriceDataTickRecordResponse));
    msg->Type = HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE;
    msg->Size = sizeof(struct s_HistoricalPriceDataTickRecordResponse);
}


#pragma pack()

#ifdef __cplusplus
}
#endif

#endif // __DTC_PROTOCOL_H__
