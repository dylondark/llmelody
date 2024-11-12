import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: rootOllamaConfig
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

        Component.onCompleted:
        {
            // load settings
            urlField.text = controller.getURL();

            // add model string from controller to modelComboBox if necessary
            modelField.text = controller.getModel();
        }

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
            TextField {
                id: modelField
                text: "llama3.2:3b"
                Layout.fillWidth: true
            }

            // ROW: EDIT PROMPT
            Label {
                text: "Edit Prompt: "
                horizontalAlignment: Text.AlignRight
                Layout.fillWidth: true
            }
            Button {
                id: editPromptButton
                text: "Edit..."
                Layout.fillWidth: true
                onClicked: {
                    var component = Qt.createComponent("OllamaPrompt.qml");
                    var ollamaPrompt = component.createObject(base);
                    ollamaPrompt.show();
                }
            }
        }

        Button {
            id: cancelButton
            text: "Cancel"
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.margins: 4
            onClicked: {
                rootOllamaConfig.close();
            }
        }

        Label {
            id: statusLabel
            text: ""
            anchors.left: cancelButton.right
            anchors.verticalCenter: cancelButton.verticalCenter
            anchors.leftMargin: 5
        }

        Button {
            id: okButton
            text: "OK"
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 4
            onClicked: {
                // save the settings
                controller.setURL(urlField.text);
                controller.setModel(modelField.text);
                rootOllamaConfig.close();
            }
        }
    }
}
