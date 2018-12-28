//
//  NCBFirstBpMeasureItem.h
//  NanochapSDK
//
//  Created by 刘帅 on 2017/12/25.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCBCommonConst.h"

@interface NCBFirstBpMeasureItem : NSObject

/// 高压
@property (nonatomic, assign) NSInteger sys;
/// 低压
@property (nonatomic, assign) NSInteger dia;
/// 心率
@property (nonatomic, assign) NSInteger heartRate;
/// 测量时间
@property (nonatomic, assign) NCBDate date;
/// 是否还有下一条数据
@property (nonatomic, assign) BOOL isNext;
@end
