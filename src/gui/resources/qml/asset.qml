import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
  property int portfolio_index
  property int asset_index
  id: root
  color: "#130e2b"

  ColumnLayout {
    anchors.fill: parent
    spacing: 0


    Button {
      text: "back"
      onClicked: {
        main_stack_view.pop()
      }
    }
    // upper
    Rectangle {
      Layout.fillWidth: true
      Layout.preferredHeight: parent.height * 0.25
      color: "#130e2b"
      //border.color: "black"

      Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
          anchors.horizontalCenter: parent.horizontalCenter
          color: "white"
          font.pointSize: 20
          text: "Portfolio: " + controller.portfolio_name + " asset: " + controller.asset_name
        }

        Text {
          color: "white"
          font.pointSize: 20
          text: " Total value: " + controller.asset_value
        }

        Button {
          anchors.horizontalCenter: parent.horizontalCenter
          text: "Add transaction"
          onClicked: add_transaction_dialog.open()
        }
      }

      Dialog {
        id: add_transaction_dialog
        anchors.centerIn: parent
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel
        height: 320

        contentItem: ColumnLayout {
          width: parent.width

          Label {
            text: "Quantity:"
            Layout.alignment: Qt.AlignHCenter
          }

          TextField {
            id: transaction_quantity_field
            Layout.fillWidth: true
            focus: true
            validator: DoubleValidator {
              bottom: 0
              decimals: 12
              notation: DoubleValidator.StandardNotation
            }

            Component.onCompleted: {
              add_transaction_dialog.aboutToShow.connect(function() {
                transaction_quantity_field.text = ""
              })
            }
          }

          Label {
            text: "Price:"
            Layout.alignment: Qt.AlignHCenter
          }

          TextField {
            id: transaction_price_field
            Layout.fillWidth: true
            focus: true
            validator: DoubleValidator {
              bottom: 0
              decimals: 5
              notation: DoubleValidator.StandardNotation
            }
            Component.onCompleted: {
              add_transaction_dialog.aboutToShow.connect(function() {
                transaction_price_field.text = ""
              })
            }
          }

          Label {
            text: "Type:"
            Layout.alignment: Qt.AlignHCenter
          }

          ComboBox {
            id: transaction_type_field
            Layout.fillWidth: true
            focus: true
            model: ["Buy", "Sell"]
          }

          Label {
            text: "Currency:"
            Layout.alignment: Qt.AlignHCenter
          }

          ComboBox {
            id: transaction_currency_field
            Layout.fillWidth: true
            focus: true
            model: ["PLN", "EUR", "USD"]
          }

          Label {
            text: "Enter Date (DD-MM-YYYY):"
            Layout.alignment: Qt.AlignHCenter
          }
          TextField {
            id: transaction_date_field
            Layout.fillWidth: true
            cursorPosition: 0

            Component.onCompleted: {
              add_transaction_dialog.aboutToShow.connect(function() {
                transaction_date_field.text = ""
              })
            }
          }
        }

        onAccepted: {
          var date_string = transaction_date_field.text
          var quantity = transaction_quantity_field.text
          var price = transaction_price_field.text
          var type = transaction_type_field.currentText
          var currency = transaction_currency_field.text

          if (quantity !== "" && price !== "") {
            var date_list = controller.validateAndGetDate(date_string)

            if (date_list.length === 3) {
              var day = date_list[0]
              var month = date_list[1]
              var year = date_list[2]

              controller.addTransaction(
                root.portfolio_index,
                root.asset_index,
                quantity,
                price,
                type,
                currency,
                day,
                month,
                year
              )
            }
          }
        }
      }
    }

    // lower
    Rectangle {
      Layout.fillWidth: true
      Layout.fillHeight: true
      color: "#130e2b"
      //border.color: "black"

      ListView {
        id: portfolioListView
        model: controller.transactions
        anchors.fill: parent
        clip: true
        spacing: 10

        delegate: Rectangle {
          anchors.horizontalCenter: parent.horizontalCenter
          width: parent.width * 0.4
          height: 60
          radius: 5
          border.color: "white"

          RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 10

            Column {
              Layout.fillWidth: true
              spacing: 3

              Text {
                text: modelData
                font.bold: true
                font.pointSize: 10
                color: modelData === "Buy" ? "green" : "red"
              }

              Text {
                text: "Value: "
                font.pointSize: 10
                color: "gray"
              }
            }

            RowLayout {
              Column {
                spacing: 3

                Button {
                  x: 0
                  text: "Manage"
                  highlighted: true
                  onClicked: {
                    console.log(root.asset_index)
                    //main_stack_view.push("transaction.qml", {"portfolio_index": index})
                  }
                }
                Button {
                  x: 0
                  text: "Remove"
                  highlighted: true
                  onClicked: {
                    controller.removeTransaction(root.portfolio_index, root.asset_index, index)
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
