//
//  NCBCommonConst.h
//  NanochapSDK
//
//  Created by 刘帅 on 2017/9/6.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#ifndef NCBCommonConst_h
#define NCBCommonConst_h

typedef struct {
    int year; // 年 有效值0-63, 从2000年开始, 17表示17年
    int month; // 月 有效值 1-12
    int day; // 日 有效值 1-31
    int hour; // 小时 有效值 0-23
    int minute; // 分钟 有效值 0-59
    int second; // 秒 有效值 0-59
}NCBDate;

typedef NS_ENUM(NSInteger, NCBFirstPulseType){
    NCBNormalPulse = 1, // 平脉
    NCBTautPulse, // 弦脉
    NCBSmoothPulse // 滑脉
};

typedef NS_ENUM(NSInteger, NCBSecondPulseType){
    NCBRetardedPulse = 1, // 迟脉
    NCBModeratePulse, // 缓脉
    NCBRapidPulse, // 数脉
    NCBKnottedPulse, // 结脉
    NCBPausingPulse, // 止脉
    NCBAbruptPulse // 促脉
};

#endif /* NCBCommonConst_h */
