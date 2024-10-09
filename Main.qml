import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("llmelody - Waiting for Connection...")

    header: ToolBar {
        id: topBar

        Row {
            anchors.fill: parent

            ToolButton {
                text: "File"
            }
            ToolButton {
                text: "Edit"
            }
            ToolButton {
                text: "Settings"
            }
        }
    }

    Pane {
        id: base
        anchors.fill: parent
    }

    footer: ToolBar {
        id: bottomBar

        RowLayout {
            anchors.fill: parent

            Label {
                id: ollamaStatus
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "Ollama: <font color=\"#FF0000\">Not Connected</font>"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }

            Label {
                id: programStatus
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "Waiting for Connection..."
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
            }
        }
    }
}
