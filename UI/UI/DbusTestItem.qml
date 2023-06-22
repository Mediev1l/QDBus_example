import QtQuick 2.15
import QtQuick.Controls 2.15

Column {
    id: root

    property alias title: title.text
    property alias pingButton: pingButton
    property alias pingText: pingText
    property alias ramButton: ramButton
    property alias ramText: ramText
    property alias statusButton: statusButton
    property alias statusText: statusText
    property alias connection: connectionText

    spacing: 5

    Text {
        id: title

        font.pixelSize: 20
        font.bold: true
    }

    Button {
        id: pingButton

        height: 50
        text: "Ping"
    }

    Text {
        id: pingText
    }

    Button {
        id: statusButton

        height: 50
        text: "Get Status"
    }

    Text {
        id: statusText

    }

    Button {
        id: ramButton

        height: 50
        text: "Get Ram Usage"
    }

    Text {
        id: ramText
    }

    Text {
        id: connectionText

        font.pixelSize: 10
        font.bold: true
    }

}
