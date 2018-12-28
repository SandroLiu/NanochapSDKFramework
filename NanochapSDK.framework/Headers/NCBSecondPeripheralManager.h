//
//  NCBSecondPeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2018/12/12.
//  Copyright © 2018年 刘帅. All rights reserved.
//

#import "NCBPeripheralManager.h"
@class NCBSecondPeripheralManager;

@protocol NCBSecondPeripheralManagerDataDelegate <NCBPeripheralManagerDataDelegate>

@optional

@end

NS_ASSUME_NONNULL_BEGIN

@interface NCBSecondPeripheralManager : NCBPeripheralManager

/// 数据回调
@property (nonatomic, weak, nullable) id<NCBSecondPeripheralManagerDataDelegate> dataDelegate;

/**
 使设备的led灯闪烁
 
 @param duraction 闪烁时间, 1亮，0灭
 */
- (void)ledFlashesForDuration:(uint8_t)duraction;

#if NCBDEBUG
/**
 发送自定义数据
 
 @param cmd cmd
 @param key key
 @param value value
 */
- (void)sendCmd:(uint8_t)cmd key:(uint8_t)key value:(NSData *_Nullable)value;
#endif
@end

NS_ASSUME_NONNULL_END
