
package server.calculator.jaxws;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;

/**
 * This class was generated by Apache CXF 3.2.1
 * Tue Nov 27 14:23:31 BRST 2018
 * Generated source version: 3.2.1
 */

@XmlRootElement(name = "divisao", namespace = "http://calculator.server/")
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "divisao", namespace = "http://calculator.server/", propOrder = {"arg0", "arg1"})

public class Divisao {

    @XmlElement(name = "arg0")
    private java.lang.Double arg0;
    @XmlElement(name = "arg1")
    private java.lang.Double arg1;

    public java.lang.Double getArg0() {
        return this.arg0;
    }

    public void setArg0(java.lang.Double newArg0)  {
        this.arg0 = newArg0;
    }

    public java.lang.Double getArg1() {
        return this.arg1;
    }

    public void setArg1(java.lang.Double newArg1)  {
        this.arg1 = newArg1;
    }

}

