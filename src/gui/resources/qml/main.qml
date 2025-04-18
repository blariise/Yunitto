import QtQuick 6.2
import QtQuick.Controls 6.2

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Portfolio Tracker"

    Button {
        text: "Click Me"
        anchors.centerIn: parent
        onClicked: console.log("Button Clicked!")
    }
}

