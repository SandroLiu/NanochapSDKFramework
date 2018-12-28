//
//  NCBPeripheralDebugDelegate.h
//  SDKDevelop
//
//  Created by 刘帅 on 2017/8/9.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NCBPeripheralDebugDelegate <NSObject>

@optional
/** 接收到的完整数据*/
- (void)NCBPeripheral:(id)peripheral receiveCompleteData:(NSString *)data;
/** 接收到解析后的数据*/
- (void)NCBPeripheral:(id)peripheral receiveAfterAnalysisData:(NSString *)data;
/** 发送的完整数据*/
- (void)NCBPeripheral:(id)peripheral writeCompleteData:(NSString *)data;
/** 发送的打包前的数据*/
- (void)NCBPeripheral:(id)peripheral writeBeforePackingData:(NSString *)data;

@end
