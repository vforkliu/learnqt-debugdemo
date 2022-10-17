import QtQuick 2.12
import QtQuick.Window 2.12
import com.xkit.ui 1.0 as XUIKit

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    XUIKit.FolderTreeView{}

    Component.onCompleted: {
        console.log("Window load finished")
        console.log("homePath:" + XUIKit.FM.homePath());
    }
}
