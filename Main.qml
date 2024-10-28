import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("llmelody - Waiting for Connection...")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
        Menu {
            title: qsTr("Options")
            MenuItem {
                text: qsTr("Settings")
                onTriggered: {
                    var component = Qt.createComponent("Settings.qml");
                    var settings = component.createObject(base);
                    settings.show();
                }
            }
        }
        Menu {
            title: qsTr("Help")
            MenuItem {
                text: qsTr("About")
                onTriggered: {
                    var component = Qt.createComponent("About.qml");
                    var about = component.createObject(base);
                    about.show();
                }
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
