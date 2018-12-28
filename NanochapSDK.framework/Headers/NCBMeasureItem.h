//
//  NCBMeasurItem.h
//  SDKDevelop
//
//  Created by 刘帅 on 2017/7/28.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NCBCommonConst.h"

@interface NCBMeasureItem : NSObject
/** 用户id*/
@property (nonatomic, assign) NSInteger userId;
/** 时间*/
@property (nonatomic, assign) NCBDate date;
/** 温度*/
@property (nonatomic, assign) NSInteger temp;
@end
