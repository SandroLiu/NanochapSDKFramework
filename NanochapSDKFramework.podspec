
Pod::Spec.new do |s|

  s.name         = "NanochapSDKFramework"
  s.version      = "0.0.1"
  s.summary      = "蓝牙SDK框架"
  s.description  = <<-DESC
                    公司内部使用蓝牙SDK框架
                   DESC
  s.license      = "MIT"
  s.homepage     = "https://192.168.98.111:82/shuai.liu/NanochapSDKFramework"
  s.author       = { "sandro" => "liushuai_ios@126.com" }
  s.platform     = :ios, "8.0"
#需要写二进制仓库
  s.source       = { :git => "https://shuai.liu@192.168.98.111:82/shuai.liu/NanochapSDKFramework.git", :tag => "#{s.version}" }
  s.public_header_files = "NanochapSDK.framework/Headers/**/*.h"
  s.source_files = "NanochapSDK.framework/Headers/**/*.h"
  #s.preserve_paths = "*.framework"
  s.frameworks = 'Foundation', 'UIKit', 'CoreBluetooth'
  s.vendored_frameworks = "NanochapSDK.framework"
end
