import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import UI 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("UI")

    Row {
        id: row

        anchors {
            left: parent.left
            top: parent.top
            margins: 10
        }
        spacing: 100

        DbusTestItem {
            id: cache

            title: "Cache"
            connection.text: "Connection: " + (UI.cacheConnected ? "Connected" : "Disconnected")
            pingText.text: UI.cachePingMessage
            statusText {
                text: "Status: " + UI.cacheStatus
                visible: UI.cacheStatus !== ""
            }
            ramButton.visible: false

            pingButton.onClicked: {
                UI.cachePingClicked()
            }

            statusButton.onClicked: {
                UI.cacheStatusClicked()
            }
        }

        DbusTestItem {
            id: hardware

             title: "Hardware"
             connection.text: "Connection: " + (UI.hardwareConnected ? "Connected" : "Disconnected")
             pingText.text: UI.hardwarePingMessage
             statusText {
                text: "Status: " + UI.hardwareStatus
                visible: UI.hardwareStatus !== ""
             }
             ramText {
                 text: UI.ramUsage
                 visible: UI.ramUsage !== 0
             }

             pingButton.onClicked: {
                 UI.hardwarePingClicked()
             }

             statusButton.onClicked: {
                 UI.hardwareStatusClicked()
             }

             ramButton.onClicked: {
                 UI.ramUsageClicked()
             }
        }
    }
}
