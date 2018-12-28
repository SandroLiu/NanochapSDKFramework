//
//  NCBSPMeasureItem.h
//  NanochapSDK
//
//  Created by 刘帅 on 2017/8/29.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <NanochapSDK/NanochapSDK.h>

@interface NCBSPMeasureItem : NCBMeasureItem

/******血氧数据组*******/
/** 血氧*/
@property (nonatomic, assign) NSInteger sp;
/** 血流灌注指数 %*/
@property (nonatomic, assign) CGFloat PI;
/** 呼吸率, 单位次/分*/
@property (nonatomic, assign) NSInteger rsp;
@end
