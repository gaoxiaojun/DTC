#ifndef __DTC_PROTOCOL_H__
#define __DTC_PROTOCOL_H__

/*
 * Data and Trading Communications Protocol (DTC Protocol)
 * This protocol is in the public domain and freely usable by anyone.
 * Documentation: http://DTCprotocol.org/index.php?page=doc_DTCMessageDocumentation.php
 * The byte ordering is little endian.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>

#pragma pack(8)

/* DTC protocol version */
#define CURRENT_VERSION                             4

/* Text string lengths. The protocol is intended to be updated to support variable length strings making these irrelevant at that time. */
#define SYMBOL_LENGTH                               64
#define EXCHANGE_LENGTH                             16
#define UNDERLYING_SYMBOL_LENGTH                    32
#define SYMBOL_DESCRIPTION_LENGTH                   48
#define EXCHANGE_DESCRIPTION_LENGTH                 48
#define ORDER_ID_LENGTH                             32
#define TRADE_ACCOUNT_LENGTH                        32
#define TEXT_DESCRIPTION_LENGTH                     96
#define TEXT_MESSAGE_LENGTH                         256

/*----Message types---- */

/* Authentication and connection monitoring */
#define LOGON_REQUEST                               1
#define LOGON_RESPONSE                              2
#define HEARTBEAT                                   3
#define DISCONNECT_FROM_SERVER_NO_RECONNECT         4
#define LOGOFF_REQUEST                              5

/* Market data */
#define MARKET_DATA_FEED_STATUS                     100
#define MARKET_DATA_REQUEST                         101
#define MARKET_DEPTH_REQUEST                        102
#define MARKET_DATA_REJECT                          103
#define MARKET_DATA_SNAPSHOT                        104
#define MARKET_DEPTH_FULL_UPDATE_20                 105
#define MARKET_DEPTH_INCREMENTAL_UPDATE             106
#define TRADE_INCREMENTAL_UPDATE                    107
#define QUOTE_INCREMENTAL_UPDATE                    108
#define FUNDAMENTAL_DATA_REQUEST                    109
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


/* Order entry and modification */
#define SUBMIT_NEW_SINGLE_ORDER                     200
#define SUBMIT_NEW_OCO_ORDER                        201
#define CANCEL_REPLACE_ORDER                        202
#define CANCEL_ORDER                                203

/* Trading related */
#define OPEN_ORDERS_REQUEST                         300
#define ORDER_UPDATE_REPORT                         301
#define OPEN_ORDERS_REQUEST_REJECT                  302
#define HISTORICAL_ORDER_FILLS_REQUEST              303
#define HISTORICAL_ORDER_FILL_REPORT                304
#define CURRENT_POSITIONS_REQUEST                   305
#define POSITION_REPORT                             306
#define CURRENT_POSITIONS_REQUEST_REJECT            307

/* Account list */
#define ACCOUNTS_REQUEST                            400
#define ACCOUNT_LIST_RESPONSE                       401

/* Symbol discovery and security definitions */
#define EXCHANGE_LIST_REQUEST                       500
#define EXCHANGE_LIST_RESPONSE                      501
#define SYMBOLS_FOR_EXCHANGE_REQUEST                502
#define UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST     503
#define SYMBOLS_FOR_UNDERLYING_REQUEST              504
#define SECURITY_DEFINITION_FOR_SYMBOL_REQUEST      506
#define SECURITY_DEFINITION_RESPONSE                507
#define SYMBOL_SEARCH_BY_DESCRIPTION                508

/* Account balance */
#define ACCOUNT_BALANCE_UPDATE                      600

/* Logging */
#define USER_MESSAGE                                700
#define GENERAL_LOG_MESSAGE                         701

/* Historical price data */
#define HISTORICAL_PRICE_DATA_REQUEST               800
#define HISTORICAL_PRICE_DATA_HEADER_RESPONSE       801
#define HISTORICAL_PRICE_DATA_REJECT                802
#define HISTORICAL_PRICE_DATA_RECORD_RESPONSE       803
#define HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE  804


/* Standard UNIX date and time value */
typedef int64_t t_DateTime;

/* This is a 4 byte DateTime value used in messages where compactness is an important consideration. */
typedef uint32_t t_DateTime4Byte;


enum LogonStatusEnum {
    LOGON_SUCCESS = 1,
    LOGON_ERROR = 2,
    LOGON_ERROR_NO_RECONNECT = 3,
    LOGON_RECONNECT_NEW_ADDRESS = 4
};


enum MessageSupportedEnum {
    MESSAGE_UNSUPPORTED = 0,
    MESSAGE_SUPPORTED = 1
};


enum TradeModeEnum {
    TRADE_MODE_DEMO = 1,
    TRADE_MODE_SIMULATED = 2,
    TRADE_MODE_LIVE = 3
};


enum RequestActionEnum {
    SUBSCRIBE = 1,
    UNSUBSCRIBE = 2,
    SNAPSHOT = 3
};


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


enum BidOrAskEnum {
    BID_ASK_UNSET = 0,
    AT_BID = 1,
    AT_ASK = 2
};


enum MarketDepthIncrementalUpdateTypeEnum {
    DEPTH_UNSET = 0,
    DEPTH_INSERT_UPDATE = 1,
    DEPTH_DELETE = 2
};


enum OrderTypeEnum {
    ORDER_TYPE_UNSET = 0,
    ORDER_TYPE_MARKET = 1,
    ORDER_TYPE_LIMIT = 2,
    ORDER_TYPE_STOP = 3,
    ORDER_TYPE_STOP_LIMIT = 4,
    ORDER_TYPE_MARKET_IF_TOUCHED = 5
};


enum TimeInForceEnum {
    TIF_UNSET = 0,
    TIF_DAY = 1,
    TIF_GOOD_TILL_CANCELED = 2,
    TIF_GOOD_TILL_DATE_TIME = 3,
    TIF_IMMEDIATE_OR_CANCEL = 4,
    TIF_ALL_OR_NONE = 5,
    TIF_FILL_OR_KILL = 6
};


enum BuySellEnum {
    BUY_SELL_UNSET = 0,
    BUY = 1,
    SELL = 2
};


enum OpenCloseTradeEnum {
    TRADE_UNSET = 0,
    TRADE_OPEN = 1,
    TRADE_CLOSE = 2
};



enum MarketDataFeedStatusEnum {
    MARKET_DATA_FEED_LOST = 1,
    MARKET_DATA_FEED_RESTORED = 2
};


enum DisplayFormatEnum {
    DISPLAY_FORMAT_UNSET =  -1,
    /* The following formats indicate the number of decimal places to be displayed */
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
    /* The following formats are fractional formats */
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


enum SecurityTypeEnum {
    ST_UNSET = 0,
    ST_FUTURE = 1,
    ST_STOCK = 2,
    ST_FOREX = 3, /* Bitcoins also go into this category */
    ST_INDEX = 4,
    ST_FUTURES_STRATEGY = 5,
    ST_STOCK_OPTION = 6,
    ST_FUTURES_OPTION = 7,
    ST_INDEX_OPTION = 8,
    ST_BOND = 9,
    ST_MUTUAL_FUND = 10
};


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

/*
#define LOGON_SUCCESS                               1
#define LOGON_ERROR                                 2
#define LOGON_ERROR_NO_RECONNECT                    3
#define LOGON_RECONNECT_NEW_ADDRESS                 4

#define MESSAGE_UNSUPPORTED                         0
#define MESSAGE_SUPPORTED                           1

#define TRADE_MODE_DEMO                             1
#define TRADE_MODE_SIMULATED                        2
#define TRADE_MODE_LIVE                             3

#define SUBSCRIBE                                   1
#define UNSUBSCRIBE                                 2
#define SNAPSHOT                                    3

#define ORDER_STATUS_UNSPECIFIED                    0
#define ORDER_STATUS_ORDERSENT                      1
#define ORDER_STATUS_PENDINGOPEN                    2
#define ORDER_STATUS_PENDINGCHILD                   3
#define ORDER_STATUS_OPEN                           4
#define ORDER_STATUS_PENDING_CANCEL_REPLACE         5
#define ORDER_STATUS_PENDING_CANCEL                 6
#define ORDER_STATUS_FILLED                         7
#define ORDER_STATUS_CANCELED                       8
#define ORDER_STATUS_REJECTED                       9

#define ET_UNSET                                    0
#define ET_OPEN_ORDERS_REQUEST                      1
#define ET_NEW_ORDER_ACCEPTED                       2
#define ET_ORDER_UPDATE                             3
#define ET_FILLED                                   4
#define ET_PARTIAL_FILL                             5
#define ET_CANCELED                                 6
#define ET_CANCEL_REPLACE_COMPLETE                  7
#define ET_NEW_ORDER_REJECT                         8
#define ET_ORDER_CANCEL_REJECT                      9
#define ET_ORDER_CANCEL_REPLACE_REJECT              10

#define BID_ASK_UNSET                               0
#define AT_BID                                      1
#define AT_ASK                                      2

#define DEPTH_UNSET                                 0
#define DEPTH_INSERT_UPDATE                         1
#define DEPTH_DELETE                                2

#define ORDER_TYPE_UNSET                            0
#define ORDER_TYPE_MARKET                           1
#define ORDER_TYPE_LIMIT                            2
#define ORDER_TYPE_STOP                             3
#define ORDER_TYPE_STOP_LIMIT                       4
#define ORDER_TYPE_MARKET_IF_TOUCHED                5

#define TIF_UNSET                                   0
#define TIF_DAY                                     1
#define TIF_GOOD_TILL_CANCELED                      2
#define TIF_GOOD_TILL_DATE_TIME                     3
#define TIF_IMMEDIATE_OR_CANCEL                     4
#define TIF_ALL_OR_NONE                             5
#define TIF_FILL_OR_KILL                            6

#define BUY_SELL_UNSET                              0
#define BUY                                         1
#define SELL                                        2

#define TRADE_UNSET                                 0
#define TRADE_OPEN                                  1
#define TRADE_CLOSE                                 2

#define MARKET_DATA_FEED_LOST                       1
#define MARKET_DATA_FEED_RESTORED                   2

#define DISPLAY_FORMAT_UNSET                        -1
//The following formats indicate the number of decimal places to be displayed
#define DISPLAY_FORMAT_DECIMAL_0                    0
#define DISPLAY_FORMAT_DECIMAL_1                    1
#define DISPLAY_FORMAT_DECIMAL_2                    2
#define DISPLAY_FORMAT_DECIMAL_3                    3
#define DISPLAY_FORMAT_DECIMAL_4                    4
#define DISPLAY_FORMAT_DECIMAL_5                    5
#define DISPLAY_FORMAT_DECIMAL_6                    6
#define DISPLAY_FORMAT_DECIMAL_7                    7
#define DISPLAY_FORMAT_DECIMAL_8                    8
#define DISPLAY_FORMAT_DECIMAL_9                    9
//The following formats are fractional formats
#define DISPLAY_FORMAT_DENOMINATOR_256              356
#define DISPLAY_FORMAT_DENOMINATOR_128              228
#define DISPLAY_FORMAT_DENOMINATOR_64               164
#define DISPLAY_FORMAT_DENOMINATOR_32_QUARTERS      136
#define DISPLAY_FORMAT_DENOMINATOR_32_HALVES        134
#define DISPLAY_FORMAT_DENOMINATOR_32               132
#define DISPLAY_FORMAT_DENOMINATOR_16               116
#define DISPLAY_FORMAT_DENOMINATOR_8                108
#define DISPLAY_FORMAT_DENOMINATOR_4                104
#define DISPLAY_FORMAT_DENOMINATOR_2                102

#define ST_UNSET                                    0
#define ST_FUTURE                                   1
#define ST_STOCK                                    2
#define ST_FOREX                                    3 // Bitcoins also go into this category
#define ST_INDEX                                    4
#define ST_FUTURES_STRATEGY                         5
#define ST_STOCK_OPTION                             6
#define ST_FUTURES_OPTION                           7
#define ST_INDEX_OPTION                             8
#define ST_BOND                                     9
#define ST_MUTUAL_FUND                              10

#define INTERVAL_TICK                               0
#define INTERVAL_1_SECOND                           1
#define INTERVAL_2_SECONDS                          2
#define INTERVAL_4_SECONDS                          4
#define INTERVAL_5_SECONDS                          5
#define INTERVAL_10_SECONDS                         10
#define INTERVAL_30_SECONDS                         30
#define INTERVAL_1_MINUTE                           60
#define INTERVAL_1_DAY                              86400
#define INTERVAL_1_WEEK                             604800
*/

#define MESSAGE_HEAD uint16_t Size; uint16_t Type

struct DTCMessageHeader {
    MESSAGE_HEAD;
};

#define GET_MESSAGE_TYPE(x) (struct DTCMessageHeader*)(x)->Type
#define GET_MESSAGE_SIZE(x) (struct DTCMessageHeader*)(x)->Size

struct s_LogonRequest
{
    MESSAGE_HEAD;
    int32_t ProtocolVersion;
    char Username[32];
    char Password[32];
    char GeneralTextData[64];
    int32_t Integer_1;
    int32_t Integer_2;
    int32_t  HeartbeatIntervalInSeconds;
    int32_t TradeMode;    /* TradeModeEnum */
    char TradeAccount[TRADE_ACCOUNT_LENGTH];
    char HardwareIdentifier[64];
    char ClientName[32];
};

struct s_LogonResponse
{
    MESSAGE_HEAD;
    int32_t ProtocolVersion;
    int32_t Result; /* LogonStatusEnum */
    char ResultText[TEXT_DESCRIPTION_LENGTH];
    char ReconnectAddress [64];
    int32_t Integer_1;
    char ServerVersion[12];
    char ServerName[24];
    char ServiceProviderName[24];
    unsigned char MarketDepthUpdatesBestBidAndAsk;
    unsigned char TradingIsSupported;
    unsigned char OCOOrdersSupported;
    unsigned char OrderCancelReplaceSupported;
    char SymbolExchangeDelimiter[4];
    unsigned char SecurityDefinitionsSupported;
    unsigned char HistoricalPriceDataSupported;
    unsigned char ResubscribeWhenMarketDataFeedRestored;
    unsigned char MarketDepthIsSupported;
    unsigned char OneHistoricalPriceDataRequestPerConnection;
};

struct s_LogoffRequest
{
    MESSAGE_HEAD;
    char Reason[TEXT_DESCRIPTION_LENGTH];
};

struct s_Heartbeat
{
    MESSAGE_HEAD;
    uint32_t DroppedMessages;
    t_DateTime CurrentDateTime;
};

struct s_DisconnectFromServer
{
    MESSAGE_HEAD;
    char DisconnectReason[TEXT_DESCRIPTION_LENGTH];
};

struct s_MarketDataFeedStatus
{
    MESSAGE_HEAD;
    int32_t Status; /* MarketDataFeedStatusEnum */
};

struct s_MarketDataFeedSymbolStatus
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    int32_t Status; /* MarketDataFeedStatusEnum */
};

struct s_MarketDataRequest
{
    uint16_t Size;
    uint16_t Type;
    int32_t RequestActionValue;   /* RequestActionEnum */
    uint16_t MarketDataSymbolID;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
};

struct s_MarketDepthRequest
{
    MESSAGE_HEAD;
    int32_t RequestActionValue;     /* RequestActionEnum */
    uint16_t MarketDataSymbolID;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
    int32_t NumberOfLevels;
};

struct s_MarketDataReject
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    char RejectText[TEXT_DESCRIPTION_LENGTH];
};

struct s_MarketDataSnapshot
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    double SettlementPrice;
    double DailyOpen;
    double DailyHigh;
    double DailyLow;
    double DailyVolume;
    uint32_t DailyNumberOfTrades;
    union
    {
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

struct s_FundamentalDataRequest
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
};

struct s_FundamentalDataResponse
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    char SymbolDescription[SYMBOL_DESCRIPTION_LENGTH];
    float TickSize;
    float TickCurrencyValue;
    int32_t DisplayFormat;  /* DisplayFormatEnum */
    float BuyRolloverInterest;
    float SellRolloverInterest;
    float OrderPriceMultiplier;
};

#define NUM_DEPTH_LEVELS20 20
struct s_MarketDepthFullUpdate20
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    struct
    {
        double Price;
        float Volume;
    } BidDepth[NUM_DEPTH_LEVELS20], AskDepth[NUM_DEPTH_LEVELS20];
};

#define NUM_DEPTH_LEVELS10 10
struct s_MarketDepthFullUpdate10
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    struct
    {
        double Price;
        float Volume;
    } BidDepth[NUM_DEPTH_LEVELS10], AskDepth[NUM_DEPTH_LEVELS10];
};

struct s_MarketDepthSnapshotLevel
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    uint16_t Side;          /* BidOrAskEnum */
    double Price;
    double Volume;
    uint16_t  Level;
    unsigned char FirstMessageInBatch;
    unsigned char LastMessageInBatch;
};

struct s_MarketDepthIncrementalUpdate
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    uint16_t Side;  /* BidOrAskEnum */
    double Price;
    double Volume;
    unsigned char UpdateType;   /* MarketDepthIncrementalUpdateTypeEnum */
};

struct s_MarketDepthIncrementalUpdateCompact
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    uint16_t Side;  /* BidOrAskEnum */
    float Price;
    float Volume;
    unsigned char UpdateType;   /* MarketDepthIncrementalUpdateTypeEnum */
};

struct s_SettlementIncrementalUpdate
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    double SettlementPrice;
};

struct s_DailyOpenIncrementalUpdate
{
    uint16_t Size;
    uint16_t Type;
    uint16_t MarketDataSymbolID;
    double DailyOpen;
};

struct s_MarketDepthReject
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    char RejectText[TEXT_DESCRIPTION_LENGTH];
};

struct s_TradeIncrementalUpdate
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    uint16_t TradeAtBidOrAsk;   /* BidOrAskEnum */
    double Price;
    double TradeVolume;
    double TradeDateTimeUnix;
};

struct s_QuoteIncrementalUpdate
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    double BidPrice;
    float BidSize;
    double AskPrice;
    float AskSize;
    double QuoteDateTimeUnix;
};

struct s_QuoteIncrementalUpdateCompact
{
    MESSAGE_HEAD;
    float BidPrice;
    float BidSize;
    float AskPrice;
    float AskSize;
    t_DateTime4Byte QuoteDateTimeUnix;
    uint16_t MarketDataSymbolID;
};

struct s_TradeIncrementalUpdateCompact
{
    MESSAGE_HEAD;
    float Price;
    float TradeVolume;
    t_DateTime4Byte TradeDateTimeUnix;
    uint16_t MarketDataSymbolID;
    uint16_t TradeAtBidOrAsk;   /* BidOrAskEnum */
};

struct s_DailyVolumeIncrementalUpdate
{
    uint16_t Size;
    uint16_t Type;

    uint16_t MarketDataSymbolID;
    double DailyVolume;
};

struct s_OpenInterestIncrementalUpdate
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    uint32_t OpenInterest;
};

struct s_DailyHighIncrementalUpdate
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    double DailyHigh;
};

struct s_DailyLowIncrementalUpdate
{
    MESSAGE_HEAD;
    uint16_t MarketDataSymbolID;
    double DailyLow;

};

struct s_SubmitNewSingleOrder
{
    MESSAGE_HEAD;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
    char ClientOrderID[ORDER_ID_LENGTH];
    int32_t OrderType;  /* OrderTypeEnum */
    int32_t BuySell;    /* BuySellEnum */
    double Price1;
    double Price2;
    int32_t TimeInForce;    /* TimeInForceEnum */
    t_DateTime GoodTillDateTimeUnix;
    double OrderQuantity;
    char TradeAccount[TRADE_ACCOUNT_LENGTH];
    char IsAutomatedOrder;
    char IsParentOrder;
    int32_t Price1AsInteger;
    int32_t Price2AsInteger;
    float Divisor;
};

struct s_CancelReplaceOrder
{
    MESSAGE_HEAD;
    char ServerOrderID[ORDER_ID_LENGTH];
    char ClientOrderID[ORDER_ID_LENGTH];
    double Price1;
    double Price2;
    double OrderQuantity;
    char TradeAccount [TRADE_ACCOUNT_LENGTH];   /* Not required by DTC */
    int32_t Price1AsInteger;
    int32_t Price2AsInteger;
    float Divisor;
};

struct s_CancelOrder
{
    MESSAGE_HEAD;
    char ServerOrderID[ORDER_ID_LENGTH];
    char ClientOrderID[ORDER_ID_LENGTH];
    char TradeAccount [TRADE_ACCOUNT_LENGTH];
    char Symbol[SYMBOL_LENGTH];     /* Not required by DTC */
    char Exchange[EXCHANGE_LENGTH]; /* Not required by DTC */

};

struct s_SubmitNewOCOOrder
{
    MESSAGE_HEAD;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
    char ClientOrderID_1[ORDER_ID_LENGTH];
    int32_t OrderType_1;    /* OrderTypeEnum */
    int32_t BuySell_1;      /* BuySellEnum */
    double Price1_1;
    double Price2_1;
    double OrderQuantity_1;
    char ClientOrderID_2[ORDER_ID_LENGTH];
    int32_t OrderType_2;    /* OrderTypeEnum */
    int32_t BuySell_2;      /* BuySellEnum */
    double Price1_2;
    double Price2_2;
    double OrderQuantity_2;
    int32_t TimeInForce;    /* TimeInForceEnum */
    t_DateTime GoodTillDateTimeUnix;
    char TradeAccount[TRADE_ACCOUNT_LENGTH];
    char IsAutomatedOrder;
    char ParentTriggerClientOrderID[ORDER_ID_LENGTH];
};

struct s_OpenOrdersRequest
{
    MESSAGE_HEAD;
    int32_t RequestID;
    int32_t RequestAllOpenOrders;
    char ServerOrderID[ORDER_ID_LENGTH];
};

struct s_HistoricalOrderFillsRequest
{
    MESSAGE_HEAD;
    int32_t RequestID;
    char ServerOrderID[ORDER_ID_LENGTH];
    int32_t NumberOfDays;
    char TradeAccount[TRADE_ACCOUNT_LENGTH];
};

struct s_CurrentPositionsRequest
{
    MESSAGE_HEAD;
    int32_t RequestID;
    char  TradeAccount[TRADE_ACCOUNT_LENGTH];
};

struct s_CurrentPositionsRequestReject
{
    MESSAGE_HEAD;
    int32_t RequestID;
    char RejectText[TEXT_DESCRIPTION_LENGTH];
};

struct s_OrderUpdateReport
{
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
    int32_t OrderStatus;        /* OrderStatusEnum */
    int32_t ExecutionType;      /* ExecutionTypeEnum */
    int32_t OrderType;          /* OrderTypeEnum */
    int32_t BuySell;            /* BuySellEnum */
    double Price1;
    double Price2;
    int32_t TimeInForce;        /* TimeInForceEnum */
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

struct s_OpenOrdersRequestReject
{
    MESSAGE_HEAD;
    int32_t RequestID;
    char RejectText[TEXT_DESCRIPTION_LENGTH];
};

struct s_HistoricalOrderFillReport
{
    MESSAGE_HEAD;
    int32_t RequestID;
    int32_t TotalNumberMessages;
    int32_t MessageNumber;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
    char ServerOrderID[ORDER_ID_LENGTH];
    int32_t BuySell;    /* BuySellEnum */
    double FillPrice;
    t_DateTime FillDateTimeUnix;
    double FillQuantity;
    char UniqueFillExecutionID[64];
    char TradeAccount[TRADE_ACCOUNT_LENGTH];
    int32_t OpenClose;  /* OpenCloseTradeEnum */
    char NoneOrderFills;
};

struct s_PositionReport
{
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

struct s_AccountsRequest
{
    MESSAGE_HEAD;
};

struct s_AccountListResponse
{
    MESSAGE_HEAD;
    int32_t TotalNumberMessages;
    int32_t MessageNumber;
    char TradeAccount[TRADE_ACCOUNT_LENGTH];
};

struct s_ExchangeListRequest
{
    MESSAGE_HEAD;
    int32_t RequestID;
};

struct s_ExchangeListResponse
{
    MESSAGE_HEAD;
    int32_t RequestID;
    char Exchange[EXCHANGE_LENGTH];
    char FinalMessage;
    char ExchangeDescription[EXCHANGE_DESCRIPTION_LENGTH];
};

struct s_SymbolsForExchangeRequest
{
    MESSAGE_HEAD;
    int32_t RequestID;
    char Exchange[EXCHANGE_LENGTH];
    int32_t SecurityType;   /* SecurityTypeEnum */
};

struct s_UnderlyingSymbolsForExchangeRequest
{
    MESSAGE_HEAD;
    int32_t RequestID;
    char Exchange[EXCHANGE_LENGTH];
    int32_t SecurityType;   /* SecurityTypeEnum */
};

struct s_SymbolsForUnderlyingRequest
{
    MESSAGE_HEAD;
    int32_t RequestID;
    char UnderlyingSymbol[UNDERLYING_SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
    int32_t SecurityType;   /* SecurityTypeEnum */
};

struct s_SymbolSearchByDescriptionRequest
{
    MESSAGE_HEAD;
    int32_t RequestID;
    char Exchange[EXCHANGE_LENGTH];
    char SymbolDescription[SYMBOL_DESCRIPTION_LENGTH];
    int32_t SecurityType;   /* SecurityTypeEnum */
};

struct s_SecurityDefinitionForSymbolRequest
{
    MESSAGE_HEAD;
    int32_t RequestID;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
    int32_t SecurityType;   /* SecurityTypeEnum */
};

struct s_SecurityDefinitionResponse
{
    MESSAGE_HEAD;
    int32_t RequestID;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
    int32_t SecurityType;       /* SecurityTypeEnum */
    char SymbolDescription[SYMBOL_DESCRIPTION_LENGTH];
    float TickSize;
    int32_t PriceDisplayFormat; /* DisplayFormatEnum */
    float TickCurrencyValue;
    char FinalMessage;
};

struct s_AccountBalanceUpdate
{
    MESSAGE_HEAD;
    double CurrentCashBalance;
    double CurrentBalanceAvailableForNewPositions;
    char AccountCurrency[8];
    char TradeAccount[TRADE_ACCOUNT_LENGTH];
};

struct s_UserMessage
{
    MESSAGE_HEAD;
    char UserMessage[TEXT_MESSAGE_LENGTH];
    char PopupMessage;
};

struct s_GeneralLogMessage
{
    MESSAGE_HEAD;
    char MessageText[128];
};

struct s_HistoricalPriceDataRequest
{
    MESSAGE_HEAD;
    int32_t RequestIdentifier;
    char Symbol[SYMBOL_LENGTH];
    char Exchange[EXCHANGE_LENGTH];
    int32_t DataInterval;   /* HistoricalDataIntervalEnum */
    t_DateTime StartDateTime;
    t_DateTime EndDateTime;
    uint32_t MaximumDaysToReturn;
    char  UseZLibCompression;
    char DividendAdjustedStockData;
    char DelayedData;
};

struct s_HistoricalPriceDataHeaderResponse
{
    MESSAGE_HEAD;
    int32_t RequestIdentifier;
    int32_t DataInterval;   /* HistoricalDataIntervalEnum */
    char RecordsUseZLibCompression;
    char NoRecordsToReturn;
};

struct s_HistoricalPriceDataReject
{
    MESSAGE_HEAD;
    int32_t RequestIdentifier;
    char RejectText[TEXT_DESCRIPTION_LENGTH];
};

struct s_HistoricalPriceDataRecordResponse
{
    MESSAGE_HEAD;
    int32_t RequestIdentifier;
    t_DateTime StartingDateTime;
    double Open;
    double High;
    double Low;
    double Last;
    double Volume;
    union
    {
        uint32_t OpenInterest;
        uint32_t NumberTrades;
    };
    double BidVolume;
    double AskVolume;
    char FinalRecord;
};

struct s_HistoricalPriceDataTickRecordResponse
{
    MESSAGE_HEAD;
    int32_t RequestIdentifier;
    double TradeDateTimeWithMilliseconds;
    uint16_t BidOrAsk;  /* BidOrAskEnum */
    double TradePrice;
    double TradeVolume;
    char FinalRecord;
};

/* Public API */
int get_request_message_size(uint16_t msg_type);
int get_respone_message_size(uint16_t msg_type);

void LogonRequest_init(struct s_LogonRequest *msg);
void LogonResponse_init(struct s_LogonResponse *msg);
void LogoffRequest_init(struct s_LogoffRequest *msg);
void Heartbeat_init(struct s_Heartbeat *msg);
void DisconnectFromServer_init(struct s_DisconnectFromServer *msg);
void MarketDataFeedStatus_init(struct s_MarketDataFeedStatus *msg);
void MarketDataFeedSymbolStatus_init(struct s_MarketDataFeedSymbolStatus *msg);
void MarketDataRequest_init(struct s_MarketDataRequest *msg);
void MarketDepthRequest_init(struct s_MarketDepthRequest *msg);
void MarketDataReject_init(struct s_MarketDataReject *msg);
void MarketDataSnapshot_init(struct s_MarketDataSnapshot *msg);
void s_FundamentalDataRequest(s_FundamentalDataRequest *msg);
void FundamentalDataResponse_init(struct s_FundamentalDataResponse *msg);
void MarketDepthFullUpdate20_init(struct s_MarketDepthFullUpdate20 *msg);
void MarketDepthFullUpdate10_init(struct s_MarketDepthFullUpdate10 *msg);
void MarketDepthSnapshotLevel_init(struct s_MarketDepthSnapshotLevel *msg);
void MarketDepthIncrementalUpdate_init(struct s_MarketDepthIncrementalUpdate *msg);
void MarketDepthIncrementalUpdateCompact_init(struct s_MarketDepthIncrementalUpdateCompact *msg);
void SettlementIncrementalUpdate_init(struct s_SettlementIncrementalUpdate *msg);
void DailyOpenIncrementalUpdate_init(struct s_DailyOpenIncrementalUpdate *msg);
void MarketDepthReject_init(struct s_MarketDepthReject *msg);
void TradeIncrementalUpdate_init(struct s_TradeIncrementalUpdate *msg);
void QuoteIncrementalUpdate_init(struct s_QuoteIncrementalUpdate *msg);
void QuoteIncrementalUpdateCompact_init(struct s_QuoteIncrementalUpdateCompact *msg);
void TradeIncrementalUpdateCompact_init(struct s_TradeIncrementalUpdateCompact *msg);
void DailyVolumeIncrementalUpdate_init(struct s_DailyVolumeIncrementalUpdate *msg);
void OpenInterestIncrementalUpdate_init(struct s_OpenInterestIncrementalUpdate *msg);
void DailyHighIncrementalUpdate_init(struct s_DailyHighIncrementalUpdate *msg);
void DailyLowIncrementalUpdate_init(struct s_DailyLowIncrementalUpdate *msg);
void SubmitNewSingleOrder_init(struct s_SubmitNewSingleOrder *msg);
void CancelReplaceOrder_init(struct s_CancelReplaceOrder *msg);
void CancelOrder_init(struct s_CancelOrder *msg);
void SubmitNewOCOOrder_init(struct s_SubmitNewOCOOrder *msg);
void OpenOrdersRequest_init(struct s_OpenOrdersRequest *msg);
void HistoricalOrderFillsRequest_init(struct s_HistoricalOrderFillsRequest *msg);
void CurrentPositionsRequest_init(struct s_CurrentPositionsRequest *msg);
void CurrentPositionsRequestReject_init(struct s_CurrentPositionsRequestReject *msg);
void OrderUpdateReport_init(struct s_OrderUpdateReport *msg);
void OpenOrdersRequestReject_init(struct s_OpenOrdersRequestReject *msg);
void HistoricalOrderFillReport_init(struct s_HistoricalOrderFillReport *msg);
void PositionReport_init(struct s_PositionReport *msg);
void AccountsRequest_init(struct s_AccountsRequest *msg);
void AccountListResponse_init(struct s_AccountListResponse *msg);
void ExchangeListRequest_init(struct s_ExchangeListRequest *msg);
void ExchangeListResponse_init(struct s_ExchangeListResponse *msg);
void SymbolsForExchangeRequest_init(struct s_SymbolsForExchangeRequest *msg);
void UnderlyingSymbolsForExchangeRequest_init(struct s_UnderlyingSymbolsForExchangeRequest *msg);
void SymbolsForUnderlyingRequest_init(struct s_SymbolsForUnderlyingRequest *msg);
void SymbolSearchByDescriptionRequest(s_SymbolSearchByDescriptionRequest *msg);
void SecurityDefinitionForSymbolRequest_init(struct s_SecurityDefinitionForSymbolRequest *msg);
void SecurityDefinitionResponse_init(struct s_SecurityDefinitionResponse *msg);
void AccountBalanceUpdate_init(struct s_AccountBalanceUpdate *msg);
void UserMessage_init(struct s_UserMessage *msg);
void GeneralLogMessage_init(struct s_GeneralLogMessage *msg);
void HistoricalPriceDataRequest_init(struct s_HistoricalPriceDataRequest *msg);
void HistoricalPriceDataHeaderResponse_init(struct s_HistoricalPriceDataHeaderResponse *msg);
void HistoricalPriceDataReject_init(struct s_HistoricalPriceDataReject *msg);
void HistoricalPriceDataRecordResponse_init(struct s_HistoricalPriceDataRecordResponse *msg);
void HistoricalPriceDataTickRecordResponse_init(struct s_HistoricalPriceDataTickRecordResponse *msg);

#ifdef __cplusplus
}
#endif

#endif /* __DTC_PROTOCOL_H__ */
