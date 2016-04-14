//
//  CustomNavVC.m
//  TradeItTest
//
//  Created by Alex Antonyuk on 4/14/16.
//  Copyright © 2016 Alex Antonyuk. All rights reserved.
//

#import "CustomNavVC.h"

@interface CustomNavVC ()

@end

@implementation CustomNavVC

- (UIInterfaceOrientationMask)supportedInterfaceOrientations
{
	return [self.topViewController supportedInterfaceOrientations];
}

- (BOOL)shouldAutorotate
{
	return [self.topViewController shouldAutorotate];
}
@end
