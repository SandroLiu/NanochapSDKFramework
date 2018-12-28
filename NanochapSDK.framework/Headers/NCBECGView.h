//
//  NCBHeartLive.h
//  SDKDevelop
//
//  Created by 刘帅 on 2017/8/11.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NCBECGView : UIView

/** 大格大小*/
@property (nonatomic, assign, readonly) NSInteger bigCellWH;
/** 大格线宽*/
@property (nonatomic, assign, readonly) CGFloat bigCellLineWidth;
/** 小格线宽*/
@property (nonatomic, assign, readonly) CGFloat smallCellLineWidth;
/** 格子线的颜色*/
@property (nonatomic, strong, readonly) UIColor *cellColor;
/** 曲线宽度*/
@property (nonatomic, assign, readonly) CGFloat curveWidth;
/** 线的颜色*/
@property (nonatomic, strong, readonly) UIColor *curveColor;

/**
 *  更新将要显示的数据
 *
 *  @param nums 心电数据
 */
- (void)updateWillDisplayECGNums:(NSArray *)nums;

/**
 *  开始显示
 */
- (void)startDisplay;

/**
 *  停止显示
 */
- (void)stopDisplay;

/**
 *  是否正在显示
 *
 *  @return YES/NO
 */
- (BOOL)isDisplay;
@end

