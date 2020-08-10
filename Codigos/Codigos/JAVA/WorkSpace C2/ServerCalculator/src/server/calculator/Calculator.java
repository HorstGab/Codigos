package server.calculator;

import javax.jws.WebMethod;
import javax.jws.WebParam;
import javax.jws.WebResult;
import javax.jws.WebService;
import javax.xml.ws.RequestWrapper;
import javax.xml.ws.ResponseWrapper;

@WebService(targetNamespace = "http://calculator.server/", portName = "CalculatorPort", serviceName = "CalculatorService")
public class Calculator {

	@WebMethod(operationName = "soma", action = "urn:Soma")
	@RequestWrapper(className = "server.calculator.jaxws.Soma", localName = "soma", targetNamespace = "http://calculator.server/")
	@ResponseWrapper(className = "server.calculator.jaxws.SomaResponse", localName = "somaResponse", targetNamespace = "http://calculator.server/")
	@WebResult(name = "return")
	public Double soma (@WebParam(name = "arg0") Double a, @WebParam(name = "arg1") Double b) {
		return a + b;
	}
	
	@WebMethod(operationName = "subtrai", action = "urn:Subtrai")
	@RequestWrapper(className = "server.calculator.jaxws.Subtrai", localName = "subtrai", targetNamespace = "http://calculator.server/")
	@ResponseWrapper(className = "server.calculator.jaxws.SubtraiResponse", localName = "subtraiResponse", targetNamespace = "http://calculator.server/")
	@WebResult(name = "return")
	public Double subtrai (@WebParam(name = "arg0") Double a, @WebParam(name = "arg1") Double b) {
		return a - b;
	}
	
	@WebMethod(operationName = "multiplica", action = "urn:Multiplica")
	@RequestWrapper(className = "server.calculator.jaxws.Multiplica", localName = "multiplica", targetNamespace = "http://calculator.server/")
	@ResponseWrapper(className = "server.calculator.jaxws.MultiplicaResponse", localName = "multiplicaResponse", targetNamespace = "http://calculator.server/")
	@WebResult(name = "return")
	public Double multiplica (@WebParam(name = "arg0") Double a, @WebParam(name = "arg1") Double b) {
		return a * b;
	}
	
	@WebMethod(operationName = "divisao", action = "urn:Divisao")
	@RequestWrapper(className = "server.calculator.jaxws.Divisao", localName = "divisao", targetNamespace = "http://calculator.server/")
	@ResponseWrapper(className = "server.calculator.jaxws.DivisaoResponse", localName = "divisaoResponse", targetNamespace = "http://calculator.server/")
	@WebResult(name = "return")
	public Double divisao (@WebParam(name = "arg0") Double a, @WebParam(name = "arg1") Double b) {
		return a / b;
	}
}
