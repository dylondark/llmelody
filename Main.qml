import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: root
    width: 640
    height: 480
    maximumWidth: 640
    maximumHeight: 480
    minimumWidth: 640
    minimumHeight: 480
    visible: true
    title: "llmelody - Waiting for Connection..."
    flags: Qt.Window | Qt.WindowMinimizeButtonHint | Qt.WindowCloseButtonHint

    Component.onCompleted: {
        updateOllamaStatus();
    }

    function updateOllamaStatus()
    {
        if (controller.getOllamaStatus())
        {
            ollamaStatus.text = "Ollama: <font color=\"#00FF00\">Connected</font>";
            root.title = "llmelody - Ready";
            programStatus.text = "Ready";
        }
        else
        {
            ollamaStatus.text = "Ollama: <font color=\"#FF0000\">Not Connected</font>";
            root.title = "llmelody - Waiting for Connection...";
            programStatus.text = "Waiting for Connection...";
        }
    }

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
                text: qsTr("Ollama Configuration...")
                onTriggered: {
                    var component = Qt.createComponent("OllamaConfig.qml");
                    var ollamaConfig = component.createObject(base);
                    ollamaConfig.show();
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

        GridLayout {
            id: baseLayout
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            columns: 2

            // ROW: INSTRUMENT
            Label {
                text: "Instrument: "
                horizontalAlignment: Text.AlignRight
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            ComboBox {
                id: instrumentComboBox
                Layout.fillHeight: false
                Layout.fillWidth: true
                editable: true
                model: ["Piano", "Guitar", "Bass", "Synth", "Strings", "Brass", "Woodwinds"]
                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                    font.pixelSize: 12
                }
            }

            // ROW: TEMPO
            Label {
                text: "Tempo: "
                horizontalAlignment: Text.AlignRight
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            RowLayout {
                Layout.fillWidth: true

                Slider {
                    id: tempoSlider
                    from: 30
                    to: 300
                    value: 120
                    stepSize: 1
                    Layout.fillHeight: false
                    Layout.fillWidth: true

                    onValueChanged: {
                        tempoField.text = tempoSlider.value;
                    }
                }
                TextField {
                    id: tempoField
                    Layout.preferredWidth: 40
                    text: "120"
                    validator: IntValidator { bottom: 30; top: 300 }
                    onTextChanged: {
                        if (tempoField.text !== "") {
                            tempoSlider.value = parseInt(tempoField.text);
                        }
                    }
                }
                Label {
                    id: bpmLabel
                    text: " BPM"
                }
            }

            // ROW: TIME SIGNATURE
            Label {
                text: "Time Signature: "
                horizontalAlignment: Text.AlignRight
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            RowLayout {
                Layout.fillWidth: true

                TextField {
                    id: timeSigTop
                    Layout.preferredWidth: 40
                    text: "4"
                    validator: IntValidator { bottom: 1; top: 20 }
                }
                Label {
                    text: "/"
                }
                TextField {
                    id: timeSigBottom
                    Layout.preferredWidth: 40
                    text: "4"
                    validator: IntValidator { bottom: 1; top: 20 }
                }
            }

            // ROW: LENGTH
            Label {
                text: "Length: "
                horizontalAlignment: Text.AlignRight
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            RowLayout {
                Layout.fillWidth: true

                Slider {
                    id: lengthSlider
                    from: 1
                    to: 32
                    value: 8
                    stepSize: 1
                    Layout.fillHeight: false
                    Layout.fillWidth: true

                    onValueChanged: {
                        lengthField.text = lengthSlider.value;
                    }
                }
                TextField {
                    id: lengthField
                    Layout.preferredWidth: 40
                    Layout.fillHeight: false
                    Layout.fillWidth: true
                    text: "8"
                    validator: IntValidator { bottom: 1; top: 32 }

                    onTextChanged: {
                        if (lengthField.text !== "") {
                            lengthSlider.value = parseInt(lengthField.text);
                        }
                    }
                }
                Label {
                    text: " measures"
                }
            }

            // ROW: KEY
            Label {
                text: "Key: "
                horizontalAlignment: Text.AlignRight
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            RowLayout {
                Layout.fillWidth: true

                ComboBox {
                    id: keyComboBox
                    Layout.fillHeight: false
                    Layout.fillWidth: true
                    model: ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"]
                    delegate: ItemDelegate {
                        text: modelData
                        width: parent.width
                        font.pixelSize: 12
                    }
                }
                ComboBox {
                    id: scaleComboBox
                    Layout.fillHeight: false
                    Layout.fillWidth: true
                    model: ["Major", "Minor"]
                    delegate: ItemDelegate {
                        text: modelData
                        width: parent.width
                        font.pixelSize: 12
                    }
                }
            }

            // ROW: MOOD
            Label {
                text: "Mood: "
                horizontalAlignment: Text.AlignRight
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            TextField {
                id: moodField
                text: "Happy"
                Layout.fillHeight: false
                Layout.fillWidth: true
            }

            // ROW: SONG SECTION
            Label {
                text: "Song Section: "
                horizontalAlignment: Text.AlignRight
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            ComboBox {
                id: sectionComboBox
                Layout.fillHeight: false
                Layout.fillWidth: true
                editable: true
                model: ["Verse", "Chorus", "Bridge", "Outro"]
                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                    font.pixelSize: 12
                }
            }

            // ROW: GENRE
            Label {
                text: "Genre: "
                horizontalAlignment: Text.AlignRight
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            ComboBox {
                id: genreComboBox
                Layout.fillHeight: false
                Layout.fillWidth: true
                editable: true
                model: ["Pop", "Rock", "Jazz", "Blues", "Country", "Folk", "Classical", "Reggae", "Rap", "Hip-Hop", "R&B", "Soul", "Electronic", "Dance", "Metal", "Punk", "Alternative", "Indie", "World", "New Age", "Ambient", "Experimental", "Other"]
                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                    font.pixelSize: 12
                }
            }

            // ROW: EXTRA INFO
            Label {
                text: "Extra Info (optional): "
                horizontalAlignment: Text.AlignRight
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            TextField {
                id: extraInfoField
                Layout.fillHeight: false
                Layout.fillWidth: true
            }

            Item {
                // blank item to take up label space
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            RowLayout {
                Layout.fillWidth: true

                Button {
                    id: generateButton
                    text: "Generate"
                }
                Button {
                    id: resetButton
                    text: "Reset"

                    onClicked: {
                        instrumentComboBox.currentIndex = 0;
                        tempoSlider.value = 120;
                        timeSigTop.text = "4";
                        timeSigBottom.text = "4";
                        lengthSlider.value = 8;
                        keyComboBox.currentIndex = 0;
                        scaleComboBox.currentIndex = 0;
                        moodField.text = "Happy";
                        sectionComboBox.currentIndex = 0;
                        extraInfoField.text = "";
                    }
                }
            }
        }
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
