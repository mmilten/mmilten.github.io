package testCases;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.Assert;
import org.testng.annotations.AfterTest;
import org.testng.annotations.BeforeTest;
import org.testng.annotations.Optional;
import org.testng.annotations.Parameters;
import org.testng.annotations.Test;
import java.util.concurrent.TimeUnit;
import utilities.LoginPage;


public class LoginSwagLabs {
    String driverPath = "C:\\Users\\sersl\\Documents\\lib\\chromedriver.exe";
    WebDriver driver;
    String baseUrl = "https://www.saucedemo.com/";
    
    LoginPage objLogin;
    
    @BeforeTest
    public void verifyLandingPage()	{
        //set the Chrome Driver path
        System.setProperty("webdriver.chrome.driver",driverPath);
        
        //Creating an object of ChromeDriver
        driver = new ChromeDriver();
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        
        //launching the specified URL
        driver.get(baseUrl);
    }
    
    @AfterTest
    public void closeBrowser() {
    	driver.close();
    	System.out.println("Closed the browser");
    }
    
    @Test
    @Parameters({"username", "password"}) 
    public void login(@Optional("Abc") String username,String password) throws InterruptedException{
    	objLogin = new LoginPage (driver);
    	String loginPageTitle = objLogin.getLoginTitle();
    	Assert.assertTrue(loginPageTitle.toLowerCase().contains("swag labs"));
    	
    	objLogin.loginIntoSwagLabs(username, password);
    	
    	String homePageUrl = objLogin.getUrl();
    	Assert.assertEquals(homePageUrl, baseUrl+"inventory.html");
    }
}


