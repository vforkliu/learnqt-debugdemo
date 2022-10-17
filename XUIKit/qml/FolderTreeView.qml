import QtQuick 2.15

Item {
    id:control
    anchors.fill:parent
    Text{
        text:"TreeView"
    }
    Component.onCompleted: {
        console.log("TreeView load finished")
        console.log("homePath:" + XUIKit.FM.homePath());
    }
}
