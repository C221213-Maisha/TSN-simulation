import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.nodes.inet.StandardHost;

network TSNNetwork
{
    parameters:
        // Parameters for ML integration
        @display("bgb=600,400");
        
    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=50,50");
        }
        
        // TSN Devices
        sender1: StandardHost {
            @display("p=100,100");
        }
        
        tsnSwitch: StandardHost {
            @display("p=300,200");
        }
        
        receiver: StandardHost {
            @display("p=500,100");
        }
        
    connections:
        sender1.ethg++ <--> { datarate=1Gbps; } <--> tsnSwitch.ethg++;
        tsnSwitch.ethg++ <--> { datarate=1Gbps; } <--> receiver.ethg++;
}