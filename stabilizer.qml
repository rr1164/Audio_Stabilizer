import QtQuick 2.6
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Window
ApplicationWindow {
    id: window
    width: 1280
    height: 720
    visible: true
    title: "Audio Stabilizer by Yousef Shora"
    
    RowLayout {
        spacing: 115
        anchors.fill: parent
        anchors.margins: 70

        ColumnLayout {
            spacing: 0
            Layout.preferredWidth: 230
            Layout.topMargin: 70
                Dial {
                    Layout.alignment: Qt.AlignHCenter
                    from: 2
                    to: 5
                    snapMode:Dial.SnapAlways
                    value: 2.5
                    stepSize: 0.5
                    onValueChanged: {
                        classStabilizer.set_division_coefficient(value)
                        division_coefficient_value.text = value
                    }
                }
                Label {
                    id: division_coefficient_value
                    text: "2.5"
                    font.pointSize: 12
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 12
                }
                Label {
                    id: division_coefficient_label
                    text: "Division Coefficient"
                    font.pointSize: 12
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 12
                }
                Dial {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 50
                    from: 0
                    to: 500
                    value:150
                    stepSize: 50
                    onValueChanged:{
                        classStabilizer.set_delay_value(value)
                        sleep_value.text = value
                    }
                }

                Label {
                    id: sleep_value
                    text: "150"
                    font.pointSize: 12
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 12
                }
                Label {
                    id: sleep_label
                    font.pointSize: 12
                    text: "Delay value(ms)"
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 12
                }
                CheckBox {
                    id: checkbox_increase_low_audio
                    Layout.topMargin: 40
                    text: qsTr("Increase Low Audio")
                    font.pointSize: 12
                    checked: false
                    hoverEnabled: false
                    onCheckedChanged:classStabilizer.set_increased_value(checked)
                    Layout.alignment: Qt.AlignHCenter
                    indicator: Rectangle {
                        implicitWidth: 26
                        implicitHeight: 26
                        x: checkbox_increase_low_audio.leftPadding
                        y: parent.height / 2 - height / 2
                        radius: 3
                        border.color: checkbox_increase_low_audio.down ? "#ff0048" : "#ff0062"

                        Rectangle {
                            width: 14
                            height: 14
                            x: 6
                            y: 6
                            radius: 2
                            color: checkbox_increase_low_audio.down ? "#ff0048" : "#ff0062"
                            visible: checkbox_increase_low_audio.checked
                        }
                    }

                    contentItem: Text {
                        text: ' ' + checkbox_increase_low_audio.text
                        font: checkbox_increase_low_audio.font
                        opacity: enabled ? 1.0 : 0.3
                        color: checkbox_increase_low_audio.down ?  "#000" : "#000"
                        verticalAlignment: Text.AlignVCenter
                        leftPadding: checkbox_increase_low_audio.indicator.width + checkbox_increase_low_audio.spacing
                    }
                }
                CheckBox {
                    id: checkbox_decrease_high_audio
                    Layout.topMargin: 25
                    text: qsTr("Decrease High Audio")
                    font.pointSize: 12
                    checked: true
                    hoverEnabled: false
                    onCheckedChanged:classStabilizer.set_decrease_value(checked)
                    Layout.alignment: Qt.AlignHCenter
                    indicator: Rectangle {
                        implicitWidth: 26
                        implicitHeight: 26
                        x: checkbox_decrease_high_audio.leftPadding
                        y: parent.height / 2 - height / 2
                        radius: 3
                        border.color: checkbox_decrease_high_audio.down ? "#ff0048" : "#ff0062"

                        Rectangle {
                            width: 14
                            height: 14
                            x: 6
                            y: 6
                            radius: 2
                            color: checkbox_decrease_high_audio.down ? "#ff0048" : "#ff0062"
                            visible: checkbox_decrease_high_audio.checked
                        }
                    }

                    contentItem: Text {
                        text: ' ' + checkbox_decrease_high_audio.text
                        font: checkbox_decrease_high_audio.font
                        opacity: enabled ? 1.0 : 0.3
                        color: checkbox_decrease_high_audio.down ? "#000" : "#000"
                        verticalAlignment: Text.AlignVCenter
                        leftPadding: checkbox_decrease_high_audio.indicator.width + checkbox_decrease_high_audio.spacing
                    }
                }
        }
        ColumnLayout {
            Layout.maximumHeight: 300
            Text {
                text: "volume level:"
                Layout.alignment: Qt.AlignTop
                font.pointSize: 15
            }
            Slider {
                id: slider_before
                Layout.topMargin: 30
                value: classStabilizer.get_before_slider_value()
                onValueChanged:{
                        classStabilizer.set_before_slider_value(value);
                }

                orientation: Qt.Vertical
                Layout.preferredWidth: 200
                Layout.fillHeight: true
                from: 1
                to: 100
                stepSize: 1
                background: Rectangle{
                    height: parent.height
                    color: "lightgrey"
                    width: 4
                    anchors.centerIn: parent
                }
                handle: Rectangle {
                        y: slider_before.topPadding + slider_before.visualPosition * (slider_before.availableHeight - height)
                        x: slider_before.leftPadding + slider_before.availableWidth / 2 - width / 2
                        color: "grey" 
                        implicitWidth: 23
                        implicitHeight: 23
                        radius: 15 // half of implicitWidth & implicitHeight to make handle round
                }
            }
            Text {
                Layout.alignment: Qt.AlignHCenter
                text: slider_before.value
                Layout.topMargin:20
                font.pointSize: 15
            }
        }
        ColumnLayout {
            Layout.maximumHeight: 300
            Text {
                text: "volume level after change:"
                font.pointSize: 15
                Layout.alignment: Qt.AlignTop
            }
            Slider {
                id: slider_after
                MouseArea {
                    anchors.fill: parent

                    acceptedButtons: Qt.AllButtons

                    onPressed: mouse.accepted = true
                }
                activeFocusOnTab: false
                Layout.topMargin: 30
                value: classStabilizer.getaftervalue()
                Connections {
                    target: classStabilizer
                    onValueChanged: slider_after.value = after_value;
                }
                orientation: Qt.Vertical
                Layout.preferredWidth: 200
                Layout.fillHeight: true
                from: 1
                to: 100
                stepSize: 1
                 handle: Rectangle {
                        y: slider_after.topPadding + slider_after.visualPosition * (slider_after.availableHeight - height)
                        x: slider_after.leftPadding + slider_after.availableWidth / 2 - width / 2
                        color: slider_after.pressed ? "grey" : "grey"
                        border.color: "black"
                        border.width: 2
                        implicitWidth: 25
                        implicitHeight: 25
                        radius: 17 // half of implicitWidth & implicitHeight to make handle round
                }
            }
            Text {
                Layout.alignment: Qt.AlignHCenter
                Layout.rightMargin:  30
                text: slider_after.value
                font.pointSize: 15
            }
        }
    }
}

