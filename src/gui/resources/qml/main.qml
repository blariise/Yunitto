import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
  color: "#130e2b"
  visible: true
  title: "Yunitto"
  width: 800
  height: 600

  StackView {
    id: main_stack_view
    anchors.fill: parent
    initialItem: "portfoliomanager.qml"
  }
}
