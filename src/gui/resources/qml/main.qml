import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
  color: "#130e2b"
  visible: true
  title: "Yunitto"
  width: 1024
  height: 768

  StackView {
    id: main_stack_view
    anchors.fill: parent
    initialItem: "portfoliomanager.qml"
  }
}
