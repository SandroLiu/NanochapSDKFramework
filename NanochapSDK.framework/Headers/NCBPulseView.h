//
//  NCBPulseView.h
//  NanochapSDK
//
//  Created by 刘帅 on 2017/8/17.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, NCBBPWaveType){
    NCBBPPulseWave,
    NCBBPBloodOxygenWave
};

@interface NCBPulseView : UIView

/** 曲线宽度*/
@property (nonatomic, assign) CGFloat curveWidth;
/** 线的颜色*/
@property (nonatomic, strong) UIColor *curveColor;
/** 波形类型*/
@property (nonatomic, assign) NCBBPWaveType waveType;

/**
 *  更新将要显示的数据
 *
 *  @param nums 心电数据
 */
- (void)updateWillDisplayPulseNums:(NSArray *)nums;

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
