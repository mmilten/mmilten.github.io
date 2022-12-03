package utilities;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;

public class LoginPage {
	
	WebDriver driver;
	
	By username = By.name("user-name");
	By password = By.name("password");
	By login = By.name("login-button");
	
	public LoginPage (WebDriver driver) {
		this.driver = driver;
	}
	
	//Set username
	public void setUsername(String strUsername) {
		driver.findElement(username).sendKeys(strUsername);
	}
	
	//Set password
	public void setPassword(String strPassword) {
		driver.findElement(password).sendKeys(strPassword);
	}
	
	//Click on login button
	public void clickLogin() {
		driver.findElement(login).click();
	}
	
	//Get the title of the login page
	public String getLoginTitle() {
		return driver.getTitle();
	}
	
	//Get the current url
	public String getUrl() {
		return driver.getCurrentUrl();
	}
	
	public void loginIntoSwagLabs (String strUsername, String strPassword) {
		this.setUsername(strUsername);
		this.setPassword(strPassword);
		this.clickLogin();
	}

}
