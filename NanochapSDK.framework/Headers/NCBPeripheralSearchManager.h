//
//  NCBPeripheralSearchManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2017/12/15.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>
@class NCBPeripheralSearchManager;
@class NCBAdvertisementItem;

@protocol NCBPeripheralSearchManagerDelegate <NSObject>
- (void)searchManager:(NCBPeripheralSearchManager *)searchManager didDiscoverPeripherlas:(NSArray<NCBAdvertisementItem *> *)advertisementItems;
@end

@interface NCBPeripheralSearchManager : NSObject

/// 搜索代理
@property (nonatomic, weak) id<NCBPeripheralSearchManagerDelegate> delegate;
/// 是否正在搜索设备
@property (nonatomic, assign, getter=isSearching) BOOL searching;

//+ (instancetype)sharedInstance;

/**
 开始搜索设备, 如果之前正在搜索会停掉之前的搜索而重新开始

 @param names 想要搜索的设备的名字
 */
- (void)startSearchPeripheralWithNames:(NSArray<NSString *> *)names;

/**
 停止搜索设备, 调用此方法代理不会回调
 */
- (void)stopSearchPeripheral;
@end
