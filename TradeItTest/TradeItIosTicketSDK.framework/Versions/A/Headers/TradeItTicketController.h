//
//  TicketController.h
//  TradeItTicketViewSDK
//
//  Created by Antonio Reyes on 7/2/15.
//  Copyright (c) 2015 Antonio Reyes. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import "TradeItStockOrEtfTradeSession.h"
#import "TradeItTicketControllerResult.h"

@interface TradeItTicketController : NSObject


/**
 *  Simplified method for presenting the TradeIt Trading Ticket portfolio flow
 *
 *  @param apiKey       Your unique key generated by TradeIt
 *  @param view         The current UIViewController of your app, on completion we dismiss the ticket and return control back to this view
 */
+(void) showPortfolioWithApiKey:(NSString *) apiKey viewController:(UIViewController *) view;

/**
 *  Full method for presenting the TradeIt Trading Ticket portfolio flow, allowing all options to be configured
 *
 *  @param apiKey       Your unique key generated by TradeIt
 *  @param view         The current UIViewController of your app, on completion we dismiss the ticket and return control back to this view
 *  @param debug        Specifies whether to include the Dummy broker for testing purposes
 *  @param callback     Code block to be executed after we have returned control of the view back to you
 */
+(void) showPortfolioWithApiKey:(NSString *) apiKey viewController:(UIViewController *) view withDebug:(BOOL) debug onCompletion:(void(^)(TradeItTicketControllerResult * result)) callback;

/**
 *  Simplified method for presenting the TradeIt Trading Ticket using only the required options
 *
 *  @param apiKey       Your unique key generated by TradeIt
 *  @param symbol       The street symbol of the stock or etf to be traded
 *  @param view         The current UIViewController of your app, on completion we dismiss the ticket and return control back to this view
 */
+(void) showTicketWithApiKey: (NSString *) apiKey symbol:(NSString *) symbol viewController:(UIViewController *) view;

/**
 *  Full method for presenting the TradeIt Trading Ticket, allowing all options to be configured
 *
 *  @param apiKey       Your unique key generated by TradeIt
 *  @param symbol       The street symbol of the stock or etf to be traded
 *  @param action       Order action can be "buy", "sell", "sellShort", or "buyToCover"
 *  @param quantity     Initial quantity, if set to nil will default to 1
 *  @param view         The current UIViewController of your app, on completion we dismiss the ticket and return control back to this view
 *  @param debug        Specifies whether to include the Dummy broker for testing purposes
 *  @param callback     Code block to be executed after we have returned control of the view back to you
 */
+ (void)showTicketWithApiKey: (NSString *) apiKey symbol:(NSString *) symbol orderAction:(NSString *) action orderQuantity:(NSNumber *)quantity viewController:(UIViewController *) view withDebug:(BOOL) debug onCompletion:(void(^)(TradeItTicketControllerResult * result)) callback;

/**
 *  Create your own instance to have more control over defaults/callbacks, after setting all properties call showTicket
 *
 *  @param apiKey Your unique id generated by TradeIt
 *  @param symbol       The street symbol of the stock or etf to be traded
 *  @param lastPrice    Last price of the security to be traded
 *  @param view         Presenting view, this is the current UIViewController of your app, on completion we dissmiss the ticket and return control back to this view.
 *
 *  @return TradeItTicketController
 */

- (id) initWithApiKey: (NSString *) apiKey symbol:(NSString *) symbol viewController:(UIViewController *) view;

/**
 *  The default number of shares to trade
 */
@property int quantity;

/**
 *  The default order action, can only be buy, sell, sellShort or buyToCover
 */
@property (copy) NSString* action;

/**
 *  The default order type, can only be market, limit, stopLimit, or stopMarket
 */
@property (copy) NSString* orderType;

/**
 *  The default order duration. Possible values are day or gtc.
 */
@property (copy) NSString* expiration;

/**
 *  Set this to get access to the Dummy trading brokerage for testing
 */
@property BOOL debugMode;

/**
 *  Completion block called after the ticket has been exited, immediately after returning control to init'd view controller
 */
@property (copy) void (^onCompletion)(TradeItTicketControllerResult * result);

/**
 *  The company symbol, to be displayed on the detail view ticket
 */
@property (copy) NSString * symbol;

/**
 *  The full company name, to be displayed on the detail view ticket
 */
@property (copy) NSString * companyName;

/**
 *  Determine whether to present the ticket in portfolio mode. Default is false
 */
@property BOOL portfolioMode;

/**
 *  After setting all desired properties, call this method to launch the ticket
 */
-(void) showTicket;

/**
 *  Use this method to clear all linked brokers off device
 */
+(void) clearSavedData;

/**
 *  @return NSArray of brokers the user is linked with, it will use the short names as documented in TradeItEMS Api
 *  if you're displaying this to the end user, you should pass the value(s) through getBrokerDisplayString
 */
+(NSArray *) getLinkedBrokers;

/**
 *  @param brokerIdentifier the broker short name as documented in TradeItEMS Api
 *  @return the consumer friendly version of the broker name (i.e. IB -> Interactive Brokers)
 */
+(NSString *) getBrokerDisplayString:(NSString *) brokerIdentifier;

@end






















