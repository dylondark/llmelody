import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    header: ToolBar {
        id: topBar
    }

    Pane {
        id: base
        anchors.fill: parent
    }

    footer: ToolBar {
        id: bottomBar
    }
}
