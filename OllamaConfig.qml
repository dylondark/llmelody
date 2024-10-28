import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 400
    height: 200
    minimumWidth: 400
    minimumHeight: 200
    maximumWidth: 400
    maximumHeight: 200
    visible: true
    title: "llmelody - Ollama Config"
    flags: Qt.Window | Qt.WindowMinimizeButtonHint | Qt.WindowCloseButtonHint

    Pane {
        id: base
        anchors.fill: parent

        GridLayout {
            id: baseLayout
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            columns: 2

            // ROW: URL
            Label {
                text: "URL: "
                horizontalAlignment: Text.AlignRight
                Layout.fillWidth: true
            }
            TextField {
                id: urlField
                text: "http://localhost:11434"
                Layout.fillWidth: true
            }
        }
    }
}
