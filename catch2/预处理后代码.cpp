static void ____C_A_T_C_H____T_E_S_T____0(); 

__pragma(warning(push) )  
namespace{ 
    Catch::AutoReg autoRegistrar1(  Catch::makeTestInvoker( &____C_A_T_C_H____T_E_S_T____0 ), 
                                    ::Catch::SourceLineInfo(     "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", 
                                                                static_cast<std::size_t>( 22 ) ), 
                                    Catch::StringRef(), 
                                    Catch::NameAndTags{ "Scenario: " "Switch on tests", "[switch_button]" } 
                                ); 
} 
__pragma(warning(pop) ) 

static void ____C_A_T_C_H____T_E_S_T____0() {
    Switcher s;
    std::cout << "init resources" << std::endl;
    __pragma(warning(push) )  
    if( Catch::Section const& catch_internal_Section2 
            = Catch::SectionInfo(   ::Catch::SourceLineInfo(    "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", 
                                                                static_cast<std::size_t>( 25 ) ), 
                                    (Catch::ReusableStringStream() << "    Given: " << "the switch is on").str() 
                                ) 
    )
    __pragma(warning(pop) ) 
    {
        std::cout << "GIVEN" << std::endl;
        s.initState( State::kOn );
        
        __pragma(warning(push) )  
        if( Catch::Section const& catch_internal_Section3 
                = Catch::SectionInfo(   ::Catch::SourceLineInfo( "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", 
                                                                static_cast<std::size_t>( 28 ) ), 
                                        (Catch::ReusableStringStream() << "     When: " << "process on").str() ) 
        ) 
        __pragma(warning(pop) ) 
        {
            std::cout << "WHEN" << std::endl;
            s.Process( State::kOn );
            __pragma(warning(push) )  
            if( Catch::Section const& catch_internal_Section4 
                    = Catch::SectionInfo(   ::Catch::SourceLineInfo(  "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", 
                                                                    static_cast<std::size_t>( 31 ) ), 
                                            (Catch::ReusableStringStream() << "     Then: " << "switch is on").str() ) 
              ) 
            __pragma(warning(pop) ) 
            {
                std::cout << "THEN" << std::endl;
                do { ; Catch::AssertionHandler catchAssertionHandler(   "REQUIRE"_catch_sr, 
                                                                        ::Catch::SourceLineInfo(    "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", 
                                                                                                    static_cast<std::size_t>( 33 ) ), 
                                                                        "s.getState() == State::kOn", 
                                                                        Catch::ResultDisposition::Normal ); 
                        try {
                            __pragma(warning(push) )  
                            catchAssertionHandler.handleExpr( Catch::Decomposer() <= s.getState() == State::kOn ); 
                            __pragma(warning(pop) ) 
                            } catch(...) 
                            { 
                                catchAssertionHandler.handleUnexpectedInflightException(); 
                            }   
                            catchAssertionHandler.complete(); 
                } while( (void)0, (false) && static_cast<bool>( !!(s.getState() == State::kOn) ) );
            }
        }
        __pragma(warning(push) )  if( Catch::Section const& catch_internal_Section5 = Catch::SectionInfo( ::Catch::SourceLineInfo( "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", static_cast<std::size_t>( 36 ) ), (Catch::ReusableStringStream() << "     When: " << "process off").str() ) ) __pragma(warning(pop) ) {
            std::cout << "WHEN" << std::endl;
            s.Process( State::kOff );
            __pragma(warning(push) )  if( Catch::Section const& catch_internal_Section6 = Catch::SectionInfo( ::Catch::SourceLineInfo( "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", static_cast<std::size_t>( 39 ) ), (Catch::ReusableStringStream() << "     Then: " << "switch is off").str() ) ) __pragma(warning(pop) ) {
                std::cout << "THEN" << std::endl;
                do { ; Catch::AssertionHandler catchAssertionHandler( "REQUIRE"_catch_sr, ::Catch::SourceLineInfo( "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", static_cast<std::size_t>( 41 ) ), "s.getState() == State::kOff", Catch::ResultDisposition::Normal ); try { __pragma(warning(push) )  catchAssertionHandler.handleExpr( Catch::Decomposer() <= s.getState() == State::kOff ); __pragma(warning(pop) ) } catch(...) { catchAssertionHandler.handleUnexpectedInflightException(); } catchAssertionHandler.complete(); } while( (void)0, (false) && static_cast<bool>( !!(s.getState() == State::kOff) ) );
            }
        }
    }
    __pragma(warning(push) )  
    if( Catch::Section const& catch_internal_Section7 
        = Catch::SectionInfo(   ::Catch::SourceLineInfo(    "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", 
                                                            static_cast<std::size_t>( 45 ) ), 
                                (Catch::ReusableStringStream() << "    Given: " << "the switch is off").str() ) ) 
    __pragma(warning(pop) ) 
    {
        std::cout << "GIVEN" << std::endl;
        s.initState( State::kOff );
        __pragma(warning(push) )  
        if( Catch::Section const& catch_internal_Section8 
            = Catch::SectionInfo( ::Catch::SourceLineInfo(  "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", 
                                                            static_cast<std::size_t>( 48 ) ), 
                                    (Catch::ReusableStringStream() << "     When: " << "process on").str() ) ) 
        __pragma(warning(pop) ) 
        {
            std::cout << "WHEN" << std::endl;
            s.Process( State::kOn );
            __pragma(warning(push) )  if( Catch::Section const& catch_internal_Section9 = Catch::SectionInfo( ::Catch::SourceLineInfo( "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", static_cast<std::size_t>( 51 ) ), (Catch::ReusableStringStream() << "     Then: " << "switch is on").str() ) ) __pragma(warning(pop) ) {
                std::cout << "THEN" << std::endl;
                do { ; Catch::AssertionHandler catchAssertionHandler( "REQUIRE"_catch_sr, ::Catch::SourceLineInfo( "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", static_cast<std::size_t>( 53 ) ), "s.getState() == State::kOn", Catch::ResultDisposition::Normal ); try { __pragma(warning(push) )  catchAssertionHandler.handleExpr( Catch::Decomposer() <= s.getState() == State::kOn ); __pragma(warning(pop) ) } catch(...) { catchAssertionHandler.handleUnexpectedInflightException(); } catchAssertionHandler.complete(); } while( (void)0, (false) && static_cast<bool>( !!(s.getState() == State::kOn) ) );
            }
        }
        __pragma(warning(push) )  if( Catch::Section const& catch_internal_Section10 = Catch::SectionInfo( ::Catch::SourceLineInfo( "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", static_cast<std::size_t>( 56 ) ), (Catch::ReusableStringStream() << "     When: " << "process off").str() ) ) __pragma(warning(pop) ) {
            std::cout << "WHEN" << std::endl;
            s.Process( State::kOff );
            __pragma(warning(push) )  if( Catch::Section const& catch_internal_Section11 = Catch::SectionInfo( ::Catch::SourceLineInfo( "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", static_cast<std::size_t>( 59 ) ), (Catch::ReusableStringStream() << "     Then: " << "switch is off").str() ) ) __pragma(warning(pop) ) {
                std::cout << "THEN" << std::endl;
                do { ; Catch::AssertionHandler catchAssertionHandler( "REQUIRE"_catch_sr, ::Catch::SourceLineInfo( "E:\\DevelopmentCode\\github_Catch2\\example.build\\catch2\\bdd_Given-When-Then\\bdd_Given-When-Then.cpp", static_cast<std::size_t>( 61 ) ), "s.getState() == State::kOff", Catch::ResultDisposition::Normal ); try { __pragma(warning(push) )  catchAssertionHandler.handleExpr( Catch::Decomposer() <= s.getState() == State::kOff ); __pragma(warning(pop) ) } catch(...) { catchAssertionHandler.handleUnexpectedInflightException(); } catchAssertionHandler.complete(); } while( (void)0, (false) && static_cast<bool>( !!(s.getState() == State::kOff) ) );
            }
        }
    }
    std::cout << "clear resources" << std::endl;
}
