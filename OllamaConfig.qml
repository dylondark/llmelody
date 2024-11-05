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

            // ROW: MODEL
            Label {
                text: "Model: "
                horizontalAlignment: Text.AlignRight
                Layout.fillWidth: true
            }
            ComboBox {
                id: modelComboBox
                Layout.fillHeight: false
                Layout.fillWidth: true
                editable: true
                model: ["llama3.2:3b", "llama3.2:1b", "llama3.1:8b", "llama3.1:70b", "llama3.1:405b", "mistral", "gemma2:2b", "gemma2:9b", "gemma2:27b"]
                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                    font.pixelSize: 12
                }
            }
        }
    }
}
