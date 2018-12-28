//
//  NCBCentralStateManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2017/8/23.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@protocol NCBCentralStateManagerDelegate <NSObject>
@optional
- (void)NCBCentralDidUpdateState:(CBCentralManagerState)state;

@end

@interface NCBCentralStateManager : NSObject

/** 中心设备蓝牙可用状态改变的代理*/
@property (nonatomic, weak) id<NCBCentralStateManagerDelegate> delegate;
/** 中心设备蓝牙状态*/
@property (nonatomic, assign, readonly)CBCentralManagerState state;

+ (instancetype)sharedInstance;
@end
