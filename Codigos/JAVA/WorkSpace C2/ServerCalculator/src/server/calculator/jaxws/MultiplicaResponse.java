
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

@XmlRootElement(name = "multiplicaResponse", namespace = "http://calculator.server/")
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "multiplicaResponse", namespace = "http://calculator.server/")

public class MultiplicaResponse {

    @XmlElement(name = "return")
    private java.lang.Double _return;

    public java.lang.Double getReturn() {
        return this._return;
    }

    public void setReturn(java.lang.Double new_return)  {
        this._return = new_return;
    }

}

