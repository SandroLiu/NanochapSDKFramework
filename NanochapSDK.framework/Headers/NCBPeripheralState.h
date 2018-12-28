//
//  NCBPeripheralConnectState.h
//  SDKDevelop
//
//  Created by 刘帅 on 2017/8/9.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#ifndef NCBPeripheralState_h
#define NCBPeripheralState_h
/// 绑定状态
typedef NS_ENUM(NSInteger, NCBPeripheralBindState){
    NCBPeripheralBindStateSucceed = 0x00,// 绑定成功
    NCBPeripheralBindStateErrorTimeout = 0x01, // 绑定超时
    NCBPeripheralBindStateErrorBinded = 0x02, // 该用户已经绑定
    NCBPeripheralBindStateDataError = 0x05, // 数据错误
    NCBPeripheralBindStateErrorUnknown // 未知错误
};
/// 解绑
typedef NS_ENUM(NSInteger, NCBPeripheralUnbindState){
    NCBPeripheralUnbindStateSucceed = 0x00, // 解绑成功
    NCBPeripheralUnbindStateError = 0x01, // 解绑失败
    NCBPeripheralUnbindStateErrorUnbinded = 0x02, // 设备已经解绑
    NCBPeripheralUnbindStateErrorNoLogin = 0x03 // 用户未登录
};
/// 登录
typedef NS_ENUM(NSInteger, NCBPeripheralLoginState){
    NCBPeripheralLoginStateSucceed = 0x00, // 登录成功
    NCBPeripheralLoginStateErrorUserId = 0x01, // 用户id不对
    NCBPeripheralLoginStateErrorLogged = 0x02, // 已经登录
    NCBPeripheralLoginStateErrorUnknown // 未知错误
};
/// 退出登录
typedef NS_ENUM(NSInteger, NCBPeripheralLogoutState){
    NCBPeripheralLogoutStateSucceed = 0x00, // 退出成功
    NCBPeripheralLogoutStateError = 0x01, // 退出失败
    NCBPeripheralLogoutStateErrorNoLogin = 0x02 // 用户未登录
};
/// 连接状态
typedef NS_ENUM(NSInteger, NCBPeripheralConnectState){
    NCBPeripheralConnectStateSucceed = 0x00, // 连接成功
    NCBPeripheralConnectStateError = 0x01, // 连接失败
};
/// 启动测试状态
typedef NS_ENUM(NSInteger, NCBPeripheralStartMeasureState) {
    NCBPeripheralStartMeasureSucceed, // 启动测试成功
    NCBPeripheralStartMeasureNOPower // 启动测试失败，电量不足
};
/// 校准状态
typedef NS_ENUM(NSInteger, NCBPeripheralCalibrationState){
    NCBPeripheralCalibrationStateSucceed = 0x00, // 校准成功
    NCBPeripheralCalibrationStateTimeout = 0x01, // 操作超时
    NCBPeripheralCalibrationStateInvalidData = 0x02, // 测量数据无效
    NCBPeripheralCalibrationStateLowPower = 0x03, // 电量低
    NCBPeripheralCalibrationStateWaveformInstability = 0x04 // 用户波形不稳
};
/// 用户信息设置
typedef NS_ENUM(NSInteger, NCBPeripheralUserInfoSettingState) {
    NCBPeripheralUserInfoSettingSucceed = 0x00, // 设置成功
    NCBPeripheralUserInfoSettingFail = 0x01 // 设置失败
};
/// 固件升级
typedef NS_ENUM(NSInteger, NCBPeripheralFirmwareUpdateState) {
    NCBPeripheralFirmwareUpdateActivate = 0x00, // 固件升级启动成功
    NCBPeripheralFirmwareUpdateErrorForLowPower = 0x01 // 电量低
};
/// 固件升级结果
typedef NS_ENUM(NSInteger, NCBPeripheralFirmwareUpdateResutl) {
    NCBPeripheralFirmwareUpdateSucceed = 0x00, // 升级成功
    NCBPeripheralFirmwareUpdateFailForLowPower = 0x01, // 电量低导致升级失败
    NCBPeripheralFirmwareUpdateCharacteristic = 0x02, // 查找OTA特征时错误
    NCBPeripheralFirmwareUpdateNoSupport = 0x03, // 固件不支持
    NCBPeripheralFirmwareUpdateFileError = 0x04, // 文件解析错误
    NCBPeripheralFirmwareUpdateValidError = 0x05, // 固件校验错误
    NCBPeripheralFirmwareUpdateInitError = 0x06, // 初始化错误
    NCBPeripheralFirmwareUpdateNoPeripheral = 0x07,
    NCBPeripheralFirmwareUpdateFailForOther = 0x0A // 其他原因导致升级失败
};
/// 工厂测试结果
typedef NS_ENUM(NSInteger, NCBFactoryTestResult) {
    NCBFactoryTestSucceess = 0x00, // 测试成功
    NCBFactoryTestFailure = 0x01, // 测试失败
    NCBFactoryTestNone = 0x02, // 测试需要人工判断
};
/// 测试失败错误码
typedef NS_ENUM(NSInteger, NCBFactoryTestErrorCode) {
    NCBFactoryTestNoError = 0x00, // 测试无错误
    NCBFactoryTestTimeout = 0x01, // 测试超时
    NCBFactoryTestDataError = 0x02, // 测试数据错误
    NCBFactoryTestCmdError = 0x03 // 测试命令错误
};
/// 恢复出厂设置结果
typedef NS_ENUM(NSInteger, NCBRestoreFactorySettingsResult) {
    NCBRestoreFactorySettingsSuccess = 0x00, // 成功
    NCBRestoreFactorySettingsBatteryPowerLow = 0x01, // 电量过低
};
#endif /* NCBPeripheralConnectState_h */
