import QtQuick 2.15
import QtCharts 2.0
import QtQuick.Shapes 1.4


Item{
    property real minimumConsumption: power_cc.minChartPowerConsumption
    property real maximumConsumption: power_cc.maxChartPowerConsumption
    property real averageConsumption: power_cc.aVGConsumption
    property real yPOSAvgConsumption: power_cc.yPosAVGLine
    property real minXVal: power_cc.minChartTDT

    id:powerConsumptionChart
    width:500
    height:550
    z:104

    ChartView {
        id:powerChart
        title: "Energy Consumption"
        anchors.fill: parent
        legend.visible: false
        antialiasing: true
        backgroundColor: "black"
        plotAreaColor: "black"

        Component.onCompleted: {
            console.log("Power consumption controller component loaded..")
            console.log(powerChart.plotArea) // todo cpp
            power_cc_mapper.series = series10
        }

        // X AXIS
        ValueAxis {
            id: xAxis
            min:minXVal
            max:0
            tickCount: 4
            color:"red"
            gridLineColor: "red"
            labelsColor: "gray"
        }

        // Y AXIS
        ValueAxis {
            id: yAxis
            min: powerConsumptionChart.minimumConsumption
            max: powerConsumptionChart.maximumConsumption
            tickCount:5
            color:"red"
            gridLineColor: "red"
            labelsColor: "gray"
        }

        LineSeries {
            id:series10
            axisX: xAxis
            axisY: yAxis
            color:"gray"
        }

        Shape {
            id:avgConsumptionLine
            width: powerChart.width
            height: powerChart.height
            z:powerChart.z+1
            anchors.centerIn: parent
            ShapePath {
                id:avgShapePath
                strokeWidth: 6
                strokeColor: "gray"
                strokeStyle: ShapePath.DashLine
                dashPattern: [ 1, 4 ]
                startX: powerChart.plotArea.x +5 ;
                startY: powerConsumptionChart.yPOSAvgConsumption
                PathLine {
                    id:avgConsumptionPathLine
                    x: powerChart.plotArea.x + powerChart.plotArea.width+7;
                    y:power_cc.yPosAVGLine
                }
            }

           Text {
                y: avgConsumptionPathLine.y
                x: avgConsumptionPathLine.x
                width:50
                height:20
                z:powerChart.z+1
                color:"white"
                text: "AVG"
            }
     }


    }
}
