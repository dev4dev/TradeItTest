//
//  ViewController.m
//  TradeItTest
//
//  Created by Alex Antonyuk on 4/4/16.
//  Copyright © 2016 Alex Antonyuk. All rights reserved.
//

#import "ViewController.h"
#import <TradeItIosTicketSDK/TradeItIosTicketSDK.h>
#import "TestViewController.h"
#import "CustomNavVC.h"

static NSString *const kApiKey = @"KEY_HERE";

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

// debug trading ticket
- (IBAction)launchTicket:(id)sender {
	[TradeItTicketController showTicketWithApiKey:kApiKey symbol:@"GE" orderAction:@"buy" orderQuantity:@1 viewController:self withDebug:YES onCompletion:nil];
}

// debug portfolio ticket
- (IBAction)launchPortfolio:(id)sender {
	[TradeItTicketController showPortfolioWithApiKey:kApiKey viewController:self withDebug:YES onCompletion:nil];
}

- (IBAction)portraitVC:(id)sender
{
	TestViewController *vc = [TestViewController new];
	[self presentViewController:[[CustomNavVC alloc] initWithRootViewController:vc] animated:YES completion:nil];
}

@end
